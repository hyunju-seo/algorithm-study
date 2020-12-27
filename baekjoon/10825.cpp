#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
struct Student {
	string name;
	int kor;
	int eng;
	int math;
};
bool compare(const Student& s1, const Student& s2) {
	if (s1.kor != s2.kor) {
		return s1.kor > s2.kor;
	}
	else if (s1.eng != s2.eng) {
		return s1.eng < s2.eng;
	}
	else if (s1.math != s2.math) {
		return s1.math > s2.math;
	}
	else {
		return s1.name < s2.name;
	}
}

bool compare2(const Student& s1, const Student& s2) {
	return make_tuple(-s1.kor, s1.eng, -s1.math, s1.name) < make_tuple(-s2.kor, s2.eng, -s2.math, s2.name);
}
int main() {
	int n;
	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; i++) {
		Student& s = students[i];
		cin >> s.name >> s.kor >> s.eng >> s.math;
	}
	sort(students.begin(), students.end(), compare2);
	for (auto s : students) {
		cout << s.name << "\n";
	}

}