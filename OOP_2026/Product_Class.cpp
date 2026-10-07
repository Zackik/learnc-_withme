#include <bits/stdc++.h>
using namespace std;

class Product{
private:
    string id, name;
    double importPrice, sellPrice;
    int quantity;
public:
    Product(){}
    Product(string id, string name, double importPrice, double sellPrice, int quantity){
        this->id = id;
        this->name = name;
        this->importPrice = importPrice;
        this->sellPrice = sellPrice;
        this->quantity = quantity;
    }
    
    double getProfit(){
        return sellPrice - importPrice;
    }
    double getTotalProfit(){
        return (sellPrice - importPrice) * quantity;
    }
    double getInventoryValue(){
        return importPrice * quantity;
    }
    void toString(){
        cout<<id << " "<< name << " "<< fixed << setprecision(2) << importPrice << " "<< fixed << setprecision(2) << sellPrice << " "<< quantity<<" "<<getProfit()<< " "<<getTotalProfit()<<" "<<getInventoryValue() <<endl;
    }
};
bool cmp(Product a, Product b){
    if(a.getInventoryValue() != b.getInventoryValue()){
        return a.getInventoryValue() > b.getInventoryValue();
    }
    return a.getProfit() > b.getProfit();
}
int main(){
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >>n;
    vector<Product> v;
    for(int i =0; i< n; i++){
        string ma, ten;
        double nhap, xuat;
        int sl;
        cin.ignore();
        getline(cin, ma); getline(cin, ten);
        cin >> nhap >> xuat >> sl;
        Product p(ma, ten, nhap, xuat, sl);
        v.push_back(p);

    }
    stable_sort(v.begin(), v.end(), cmp);
    for(Product p : v){
        p.toString();
    }


}