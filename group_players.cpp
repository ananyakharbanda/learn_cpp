#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::vector<std::pair<std::string, std::string>> team_pairs;
    team_pairs = {{"Alice","Red"}, {"Bob","Blue"}, {"Carol","Red"}, {"Dave","Blue"}, {"Eve","Red"}};
    
    std::map<std::string, std::vector<std::string>> teams;
    
    for (const auto& p : team_pairs) {
        teams[p.second].push_back(p.first);
    }
    
    for (const auto& team : teams) {
        std::cout << team.first << ": ";
        for (const auto& player : team.second) {
            std::cout << player << " ";
        }
        std::cout << "\n";
    }
}
