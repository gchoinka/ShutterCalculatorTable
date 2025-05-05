#include <algorithm>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <format>
#include <cmath>

struct Filter {
    int stops;
    std::string name;

    auto operator<=>(const Filter& other) const {
        return stops <=> other.stops;
    }

    Filter operator+(const Filter& other) const {
        return {
            .stops = this->stops + other.stops,
            .name = this->name + " " + other.name
        };
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{: >7}", name);
    }
};

struct Shutter {
    double time;

    explicit Shutter(const int initFraction) {
        time = 1.0 / initFraction;
    }

    explicit Shutter(const int initSeconds, const int initHundredsMiliseconds) {
        time  = initSeconds + initHundredsMiliseconds / 10.0;
    }

    [[nodiscard]] std::string toStringWithFilterStops(const int stops) const {
        // Increase the shutter time first by x amount of stops and then print it
        const double increasedShutterTime = time * (1 << stops);
        return doubleToString(increasedShutterTime);
    }

    [[nodiscard]] std::string toString() const {
        return doubleToString(time);
    }

private:
    [[nodiscard]] static std::string doubleToString(const double input) {
        if (input <= 0.25) {
            // Regular fraction format 1/x is used upto 1s/4
            return std::format("{:7}", static_cast<int>(std::round(1.0/input)));
        }
        else if (input <= 30.0) {
            // Regular s"ms format used between 1s/4 and 30s
            int second = std::floor(input);
            int leftOver = static_cast<int>(std::round( (input - second) * 10));
            return std::format("{:5}\"{}", second, leftOver);
        }

        // It's longer than 30 seconds, need to use BULB mode format
        const int secondTotal = std::ceil(input);
        const int minutesTotal = secondTotal / 60;
        const int seconds = secondTotal % 60;

        if (minutesTotal <= 60) {
            // it's under 1h then do not display hours yet
            return std::format("{:2}' {:02}\"", minutesTotal, seconds);
        }

        // It's over 60mins
        const int hours = minutesTotal / 60;
        const int minutes = minutesTotal % 60;

        if (hours > 99) {
            // Canon 90D can't record for longer than 99h in BULB mode, no point to display anything
            return std::format("{:7}", 'x');
        }

        // Display BULB hours and minutes (but omit seconds)
        return std::format("{:2}h {:02}'", hours, minutes);
    }
};

// My personal selection of ND filters
std::array<Filter ,4> filters = {{
    {10, "1k"}, // ND1000
    {6, "64"},  // ND64
    {3, "8"},   // ND8
    {2, "4"},   // ND4
}};

std::vector<Filter> combined;

// Shutter speeds supported by my Canon 90D but commented some extreme values I will not need
std::vector<Shutter> shutters = {
    // Fraction-based shutter speeds (e.g., 1/8000 second)
    // Shutter(8000),
    // Shutter(6400),
    // Shutter(5000),
    Shutter(4000),
    Shutter(3200),
    Shutter(2500),
    Shutter(2000),
    Shutter(1600),
    Shutter(1250),
    Shutter(1000),
    Shutter(800),
    Shutter(640),
    Shutter(500),
    Shutter(400),
    Shutter(320),
    Shutter(250),
    Shutter(200),
    Shutter(160),
    Shutter(125),
    Shutter(100),
    Shutter(80),
    Shutter(60),
    Shutter(50),
    Shutter(40),
    Shutter(30),
    Shutter(25),
    Shutter(20),
    Shutter(15),
    Shutter(13),
    Shutter(10),
    Shutter(8),
    Shutter(6),
    Shutter(5), // 1/5 => 0.200s
    Shutter(4), // 1/4 => 0.250s

    // Decimal second based shutter speeds 0"3 = 0.3s
    Shutter(0, 3),   //  0.3s
    Shutter(0, 4),   //  0.4s
    Shutter(0, 5),   //  0.5s
    Shutter(0, 6),   //  0.6s
    Shutter(0, 8),   //  0.8s
    Shutter(1, 0),   //  1.0s
    Shutter(1, 3),   //  1.3s
    Shutter(1, 6),   //  1.6s
    Shutter(2, 0),   //  2.0s
    Shutter(2, 5),   //  2.5s
    Shutter(3, 2),   //  3.2s
    Shutter(4, 0),   //  4.0s
    Shutter(5, 0),   //  5.0s
    Shutter(6, 0),   //  6.0s
    Shutter(8, 0),   //  8.0s
    Shutter(10, 0),  // 10.0s
    Shutter(13, 0),  // 13.0s
    Shutter(15, 0),  // 15.0s
    Shutter(20, 0),  // 20.0s
    Shutter(25, 0),  // 25.0s
    Shutter(30, 0),  // 30.0s
};

void populateFiltersWithHandPickedCombinations() {
    // ND1k ND64 ND4
    combined.push_back(filters[0] + filters[1]  + filters[3]);

    // ND1k ND8 ND4
    combined.push_back(filters[0] + filters[2]  + filters[3]);
    combined.push_back( {
        .stops = filters[0].stops + filters[2].stops + filters[3].stops,
        .name = filters[0].name + " " + filters[2].name + " " + filters[3].name
    } );
}

void populateFiltersWithGeneratedCombinations() {
    // Only one Filter used
    for (int i=0; i<4; i++) {
        combined.push_back(filters[i]);
    }

    // Two filter stack used
    for (int i=0; i<(4-1); i++) {
        for (int j=i+1; j<4; j++) {
            combined.push_back(filters[i] + filters[j]);
        }
    }

    // // Three filter stack used
    // for (int i=0; i<(4-2); i++) {
    //     for (int j=i+1; j<(4-1); j++) {
    //         for (int k=j+1; k<4; k++) {
    //             combined.push_back( {
    //                 .stops = filters[i].stops + filters[j].stops + filters[k].stops,
    //                 .name = filters[i].name + " " + filters[j].name + " " + filters[k].name
    //             } );
    //         }
    //     }
    // }
    //
    // // Four filters used
    // combined.push_back( {
    //     .stops = filters[0].stops + filters[1].stops + filters[2].stops + filters[3].stops,
    //     .name = filters[0].name + " " + filters[1].name + " " + filters[2].name  + " " + filters[3].name
    // } );
}

void sortFilters() {
    std::sort(combined.begin(), combined.end());
}

void displayMarkdownTable() {
    std::cout << "| no ND   | ";
    for (const auto &filter: combined) {
        std::cout << filter.toString() << " | ";
    }
    std::cout << std::endl;

    std::cout << "| ------- | ";
    for (int i=0; i<combined.size(); i++) {
        std::cout << "------- | ";
    }
    std::cout << std::endl;

    for (const auto &shutter: shutters) {
        std::cout << "| " << shutter.toString() << " | ";

        for (const auto &[stops, _]: combined) {
            std::cout << shutter.toStringWithFilterStops(stops) << " | ";
        }

        std::cout << std::endl;
    }
}

void displayCsvHeader() {
    std::cout << std::endl;

    std::cout << "  no ND";
    for (const auto &filter: combined) {
        std::cout  << ",  " << filter.toString();
    }
    std::cout << std::endl;
}

void displayCsvRow(const Shutter shutter) {
    std::cout << shutter.toString();

    for (const auto &[stops, _]: combined) {
        std::cout << ",  " << shutter.toStringWithFilterStops(stops);
    }

    std::cout << std::endl;
}

void displayCsvTable() {
    const int shuttersCount = static_cast<int>(shutters.size());
    const int middle = shuttersCount / 2;

    for (int i=0; i<shuttersCount; i++) {
        if ( (i%middle) == 0) {
            // this will trigger header twice, in begining and in middle of the table
            displayCsvHeader();
        }
        displayCsvRow(shutters[i]);
    }
}

int main() {
    populateFiltersWithGeneratedCombinations();
    populateFiltersWithHandPickedCombinations();
    sortFilters();

    displayMarkdownTable();
    displayCsvTable();

    return 0;
}
