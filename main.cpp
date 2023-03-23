#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

constexpr auto inf = 987654321;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	int n_{ 0 };
	vvi e_{};
	vvi dist_{};

public:
	void input() {
		cin >> n_;

		e_ = vvi(n_, vi(n_));
		for (auto i = 0; i < n_; ++i) {
			for (auto j = 0; j < n_; ++j) {
				cin >> e_[i][j];
			}
		}
	}

	void solve() {
		dist_ = vvi(n_, vi(n_));
		for (auto i = 0; i < n_; ++i) {
			for (auto j = 0; j < n_; ++j) {
				if (0 == e_[i][j]) {
					dist_[i][j] = inf;
				}
				else {
					dist_[i][j] = e_[i][j];
				}
			}
		}

		for (auto k = 0; k < n_; ++k) {
			for (auto i = 0; i < n_; ++i) {
				for (auto j = 0; j < n_; ++j) {
					dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);
				}
			}
		}
	}

	void printAns() noexcept {
		for (const auto& r : dist_) {
			for (const auto& x : r) {
				cout << (x < inf ? 1 : 0) << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto s = solution();
	s.input();
	s.solve();
	s.printAns();

	return 0;
}