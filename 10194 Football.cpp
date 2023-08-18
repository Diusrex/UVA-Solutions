#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Results {
    int points = 0;

    int played = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;

    int scored = 0;
    int against = 0;

    string lower_name;
};

bool Compare(const pair<string, Results>& a, const pair<string, Results>& b) {
    const auto& ra = a.second;
    const auto& rb = b.second;
    if (ra.points != rb.points) {
        return ra.points > rb.points;
    }
    if (ra.wins != rb.wins) {
        return ra.wins > rb.wins;
    }
    if (ra.scored - ra.against != rb.scored - rb.against) {
        return ra.scored - ra.against > rb.scored - rb.against;
    }
    if (ra.scored != rb.scored) {
        return ra.scored > rb.scored;
    }
    if (ra.played != rb.played) {
        return ra.played < rb.played;
    }
    return ra.lower_name < rb.lower_name;
}

int main() {
    int T;
    cin >> T;
    string line;
    getline(cin, line);

    string sep = "";

    while (T--) {
        // Tourney.
        getline(cin, line);
        cout << sep << line << '\n';
        sep = "\n";

        int N;
        cin >> N;
        getline(cin, line);

        map<string, Results> points;
        for (int i = 0; i < N; ++i) {
            getline(cin, line);
            // Ensure all teams are known, in-case they don't show up later.
            points[line].lower_name = line;
            for (int i = 0; i < line.size(); ++i) {
                points[line].lower_name[i] = std::tolower(line[i]);
            }
        }

        int G;
        cin >> G;
        getline(cin, line);

        while (G--) {
            getline(cin, line);
            int i = 0;
            while (line[i] != '#') {
                ++i;
            }
            string t1 = line.substr(0, i);

            // Pass hash.
            ++i;

            int t1_score = 0;
            while (line[i] != '@') {
                t1_score = (t1_score * 10) + (line[i] - '0');
                ++i;
            }

            ++i;

            int t2_score = 0;
            while (line[i] != '#') {
                t2_score = (t2_score * 10) + (line[i] - '0');
                ++i;
            }

            // Pass hash.
            ++i;

            string t2 = line.substr(i);

            auto& r1 = points[t1];
            auto& r2 = points[t2];

            ++r1.played;
            ++r2.played;

            r1.scored += t1_score;
            r2.against += t1_score;

            r2.scored += t2_score;
            r1.against += t2_score;

            if (t1_score > t2_score) {
                r1.points += 3;

                ++r1.wins;
                ++r2.losses;
            } else if (t1_score == t2_score) {
                r1.points += 1;
                r2.points += 1;

                ++r1.ties;
                ++r2.ties;
            } else {
                r2.points += 3;

                ++r2.wins;
                ++r1.losses;
            }
        }

        vector<pair<string, Results>> output(points.begin(), points.end());

        sort(output.begin(), output.end(), Compare);

        int i = 1;
        for (const auto& o : output) {
            const auto& r = o.second;
            printf("%i) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   i++, o.first.c_str(), r.points, r.played, r.wins, r.ties, r.losses, r.scored - r.against, r.scored, r.against);
        }
    }
}