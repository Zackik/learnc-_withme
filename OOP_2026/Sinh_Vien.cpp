#include <bits/stdc++.h>
using namespace std;

class SinhVien{
private:
    string ma, ten;
    double gpa;
    // static int cnt;
public:
    SinhVien(){
        // ++cnt;
    }
    SinhVien(string ma, string ten, double gpa){
        this->ma = ma;
        this->ten = ten;
        this->gpa = gpa;
        // ++cnt;
    }
    void in(){
        cout<<ma << " " << ten <<" "<<gpa << endl;
    }
    friend bool operator < (SinhVien a, SinhVien b){
        return a.gpa < b.gpa;
    }
    // << >>
    friend ostream& operator << (ostream &out, SinhVien s){
        out << s.ma << " " << s.ten << " " << s.gpa << endl;
    }
    friend istream& operator >> (istream &in, SinhVien &s){
        getline(in, s.ma);
        getline(in, s.ten);
        in >> s.gpa;
        return in;
    }

};

// int SinhVien :: cnt = 0;
int main(){
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    SinhVien a("B20DCCN001", "Nguyen Van A", 3.5);
    cin >> a;
    cout<< a << endl;
    // cout<< a;
    // SinhVien b("B20DCCN002", "Nguyen Van B", 3.7);
    // if(a < b) cout<< "YES\n";

}