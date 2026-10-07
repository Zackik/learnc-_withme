#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//Encapsulation: tinh dong goi
class SanPham{
private:
    string ma, ten;
    double gia;
public:
    //ham tao khong co tham so
    SanPham(){
        cout<<"Ham tao khong co tham so duoc goi"<< endl;
        ma = "SP0001";
        ten = "SP";
        gia = 0;
    }
    //ham tao day du tham so (contructor)
    SanPham(string ma, string ten, double gia){
        this->ma = ma;
        this->ten = ten;
        this->gia = gia;
    }
    //get
    string getten(){
        return ten;
    }
    double getgia(){
        return gia;
    }
    //set
    void setten(string ten){
        this->ten = ten;
    }
    void setgia(double gia){
        this->gia = gia;
    }
    void hienthi(){
        cout<< ma << " "<< ten<< " "<< fixed << setprecision(2) << gia << endl;
    }
};

int main(){
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    #endif
    SanPham p;
    
    p.hienthi();
    SanPham t("SP1", "Laptop", 100);
    t.hienthi();
}