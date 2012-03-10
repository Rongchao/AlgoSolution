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

struct DoubleRoshambo {
	int maxScore(vector <string> A, vector <string> E);
};

bool win(char a, char b) {
	return (a == 'R' && b == 'S')
		|| (a == 'S' && b == 'P')
		|| (a == 'P' && b == 'R');
}

int pt(string a, string b) {
	if (win(a[1], b[1])) {
		if (win(a[0], b[0])) {
			return 2;
		} else if (a[0] == b[0]) {
			return 1;
		}
	}
	return 0;
}

int DoubleRoshambo::maxScore(vector <string> A, vector <string> E) {
	int n = A.size();
	int m = 0;
	for (int t = 2; t >= 0; --t) {
		FOR (i, n) {
			if (A[i] == "") {
				continue;
			}
			FOR (j, n) {
				if (E[j] == "") {
					continue;
				}
				if (pt(A[i], E[j]) == t) {
					m += t;
					A[i] = "";
					E[j] = "";
					break;
				}
			}
		}
	}
	return m;
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
        string AARRAY[] = {"RR"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string EARRAY[] = {"SS"};
        vector <string> E( EARRAY, EARRAY+ARRSIZE(EARRAY) );
        DoubleRoshambo theObject;
        eq(0, theObject.maxScore(A, E),2);
    }
    {
        string AARRAY[] = {"SR", "PP"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string EARRAY[] = {"PR", "RS"};
        vector <string> E( EARRAY, EARRAY+ARRSIZE(EARRAY) );
        DoubleRoshambo theObject;
        eq(1, theObject.maxScore(A, E),1);
    }
    {
        string AARRAY[] = {"PP", "PP", "PP", "PP"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string EARRAY[] = {"RR", "PR", "SS", "SP"};
        vector <string> E( EARRAY, EARRAY+ARRSIZE(EARRAY) );
        DoubleRoshambo theObject;
        eq(2, theObject.maxScore(A, E),3);
    }
    {
        string AARRAY[] = {"PS", "RS", "PP", "SP", "RR", "SS", "SP"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string EARRAY[] = {"RP", "SP", "RR", "SR", "RS", "SP", "SS"};
        vector <string> E( EARRAY, EARRAY+ARRSIZE(EARRAY) );
        DoubleRoshambo theObject;
        eq(3, theObject.maxScore(A, E),10);
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
/// END CUT HERE
