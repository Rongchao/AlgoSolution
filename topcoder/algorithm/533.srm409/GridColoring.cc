#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstring>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
#define WATASHI_PC

inline void errf(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
	errf("{");
	FOR(i, v.size()) {
		errf(fmt, v[i]);
	}
	errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef WATASHI_PC
#define errf(fmt, ...) do { } while (false)
#endif

struct GridColoring {
	double area(int K, int rows, int cols);
};

const int MAXN = 1024;
double a[MAXN][MAXN];

double GridColoring::area(int K, int r, int c) {
	double rr = r * r, cc = c * c, ans = 0.0;
	FOR (i, r) {
		FOR (j, c) {
			a[i][j] = 1.0;
			a[i][j] *= (2 * (i + 1) * (r - i) - 1) / rr;
			a[i][j] *= (2 * (j + 1) * (c - j) - 1) / cc;
	//		printf("[%d][%d] = %lf\n", i, j, a[i][j]);
			ans += 1.0 - pow(1.0 - a[i][j], K);
		}
	}
	return ans;
}

/// BEGIN CUT HERE
// TODO
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	os << "{";
	FOR(i, v.size()) {
		os << "\"" << v[i] << "\",";
	}
	os << "}";

	return os;
}

template<typename S, typename T>
void eq(int id, S v1, T v2) {
	ostringstream s1, s2;

	s1 << v1;
	s2 << v2;

	errf("Case #%d: ", id);
	if (s1.str() == s2.str()) {
		errf("\033[1;32mPassed\033[0m\n");
	} else {
		errf("\033[1;31mFailed\033[0m\n");
		errf("\tReceived \"%s\"\n", s1.str().c_str());
		errf("\tExpected \"%s\"\n", s2.str().c_str());
	}
}

int main(int argc, char *argv[]) {
	    {
        GridColoring theObject;
        eq(0, theObject.area(1, 2, 1),1.5);
    }
    {
        GridColoring theObject;
        eq(1, theObject.area(2, 2, 1),1.875);
    }
    {
        GridColoring theObject;
        eq(2, theObject.area(1, 2, 2),2.25);
    }
    {
        GridColoring theObject;
        eq(3, theObject.area(3, 5, 7),19.11917924647044);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * first second iterator
 * push_back priority_queue
 */
/*
 * vim: ft=cpp.doxygen
 */

// TODO: 857.81 orz
/// END CUT HERE
