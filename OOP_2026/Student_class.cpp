#include <bits/stdc++.h>
using namespace std;

// Chuyển ngày sinh từ dd/mm/yyyy -> yyyymmdd
string convert(string s) {
    stringstream ss(s);

    string d, m, y;

    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    return y + m + d;
}

class Student {
private:
    string id;
    string name;
    string address;
    double gpa;
    string BoD;

public:
    // Constructor không tham số
    Student() {
        cout << "Ham tao khong co tham so duoc goi" << endl;

        this->id = "BH834";
        this->name = "Nguyen Van A";
        this->address = "Ha Noi";
        this->gpa = 0;
        this->BoD = "01/01/2000";
    }

    // Constructor có tham số
    Student(string id, string name, string address, double gpa, string BoD) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->gpa = gpa;
        this->BoD = BoD;
    }

    // Chuẩn hóa tên
    void normalizeName() {
        stringstream ss(name);

        string res;
        string w;

        while (ss >> w) {
            // Chữ cái đầu viết hoa
            res += toupper(w[0]);

            // Các chữ còn lại viết thường
            for (int i = 1; i < w.size(); i++) {
                res += tolower(w[i]);
            }

            res += " ";
        }

        // Xóa dấu cách cuối
        if (!res.empty()) {
            res.pop_back();
        }

        name = res;
    }

    // Chuẩn hóa ngày sinh
    void normalizeDateOfBirth() {
        // Ví dụ:
        // 1/5/2004 -> 01/5/2004
        if (BoD[1] == '/') {
            BoD = "0" + BoD;
        }

        // 01/5/2004 -> 01/05/2004
        if (BoD[4] == '/') {
            BoD.insert(3, "0");
        }
    }

    // In thông tin sinh viên
    void toString() {
        cout << id << " "
             << name << " "
             << address << " "
             << fixed << setprecision(2) << gpa << " "
             << BoD << endl;
    }

    // Getter GPA
    double getGpa() {
        return gpa;
    }

    // Getter ID
    string getId() {
        return id;
    }

    // Getter ngày sinh
    string getBoD() {
        return BoD;
    }

    // Destructor
    ~Student() {
        cout << "Ham huy duoc goi" << endl;
    }
};

// Hàm so sánh để sort
bool cmp(Student a, Student b) {

    // Nếu ngày sinh khác nhau
    if (a.getBoD() != b.getBoD()) {
        return convert(a.getBoD()) < convert(b.getBoD());
    }

    // Nếu ngày sinh giống nhau
    // thì sắp xếp theo ID tăng dần
    return a.getId() < b.getId();
}

int main() {

#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<Student> v;

    for (int i = 0; i < n; i++) {

        string id;
        string name;
        string address;
        string BoD;
        double gpa;

        cin.ignore();

        getline(cin, id);
        getline(cin, name);
        getline(cin, address);
        getline(cin, BoD);

        cin >> gpa;

        // Tạo Student
        Student s(id, name, address, gpa, BoD);

        // Chuẩn hóa
        s.normalizeName();
        s.normalizeDateOfBirth();

        // Thêm vào vector
        v.push_back(s);
    }

    // Sắp xếp
    sort(v.begin(), v.end(), cmp);

    // In kết quả
    for (int i = 0; i < n; i++) {
        v[i].toString();
    }
    return 0;
}