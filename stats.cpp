#include "stats.h"
#include <algorithm>
#include <numeric>
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    Stats stats;

    if (data.empty()) {
        stats.average = std::nanf("");  // Ensure NAN is properly assigned
        stats.max = std::nanf("");
        stats.min = std::nanf("");
        return stats;
    }

    stats.average = std::accumulate(data.begin(), data.end(), 0.0f) / data.size();
    stats.max = *std::max_element(data.begin(), data.end());
    stats.min = *std::min_element(data.begin(), data.end());

    return stats;
}
