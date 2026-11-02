#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[1000001];//1000002 = 1e6 + 2
const int MOD = 1e9 + 7;
int f[1001];
void ktao(){
    int fibo[20];
    fibo[0] = 0, fibo[1] = 1;
    for(int i = 2; i <= 19; i++){
        fibo[i] = fibo[i -1] + fibo[i - 2];
    }
    for (int i = 0; i < 20; i++) {
    if (fibo[i] <= 1000) {
        f[fibo[i]] = 1;
    }
}
}


int main(){
    //bai 1
    // int TC; cin>>TC;
    // while(TC--){
    //     int n; cin>>n;
    //     map<ll,bool>mp;
    //     for(int i= 0; i<n; i++){
    //         ll x; cin>>x;
    //         mp[x] = true;
    //     }
    //     for(int i =0; i<n; i++){
    //         if(mp[i]){
    //             cout<<i << " ";
    //         }else cout<< "-1 ";
    //     }
    //     cout<<endl;
    // }
    //bai 2
    // int TC; cin>>TC;
    // while(TC--){
    //     int n; cin>>n;
    //     memset(cnt,0,sizeof(cnt));
    //     for(int i=0; i< n; i++){
    //         int x; cin>>x;
    //         if(x >0) cnt[x] = 1;
    //     }
    //     for(int i =1; i<= 1000001; i++){
    //         if(cnt[i] ==0){
    //             cout<<i<<endl;
    //             break;
    //         }  
    //     }
    //     cout<<endl;
    // }
    //bai 3
    // int TC; cin>>TC;
    // while(TC--){
    //     int n; cin>>n;
    //     int a[n];
    //     for(int i=0; i,n; i++){
    //         cin>> a[i];
    //     }
    //     int res = INT_MAX;
    //     for(int i=0; i<n; i++){
    //         for(int j = i+1; j<n; j++){
    //             res = min(res, max(a[i], a[j]) - min(a[i], a[j]));
    //         }
    //     }
    //     cout<<res<<endl;
    // }
    //bai 4
    // int TC; cin>>TC;
    // while(TC--){
    //     int n; cin>>n>>k;
    //     int a[n];
    //     for(int i=0; i<n; i++) cin>> a[i];
    //     sort(a, a+n,greater<int>());
    //     for(int i=0; i<k; i++){
    //         cout<<a[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    //bai 5
    // int TC; cin>>TC;
    // while(TC--){
    //     int n; cin>>n;
    //     int a[n];
    //     memset(cnt,0,sizeof(cnt));
    //     for(int i=0; i<n; i++){
    //         cin>>a[i];
    //         cnt[a[i]]++;
    //     }
    //     int ans =0;
    //     for(int i =0; i<n ; i++){
    //         if(cnt[a[i]] >= 2){
    //             ++ans;
    //         }
    //     }
    //     cout<<ans <<endl;
    // }
    //bai 6
    // int TC; cin>>TC;
    // while(TC--){
    //     int n,x; cin>>n>>x;
    //     int a[n];
    //     for(int i =0; i<n; i++) cin>>a[i];
    //     ll lt = 1, res =0;
    //     for(int i= n -1; i>= 0; i--){
    //         res += a[i] * lt;
    //         res %= MOD;
    //         lt *= x;
    //         lt %= MOD;
    //     }
    //     cout<<res <<endl;
    // }
    /*
    Poplynomial Evaluation (gia tri da thuc)
    input 
    1
5 2
0 1 3 4 7
TC= 1, n = 5, x = 2 la gia tri can thay vao da thuc. a[] = {0,1,3,4,7} la he so cua da thuc.
 Bai toan thuc hien phep tinh: P(x) = a0 + a1x + a2x^2 + ..+ an-1x^(n-1)

Thay so: P(2)= 0 ++ 1(2) + 3(2^2) + 4(2^3) + 7(2^4) = 0 + 2 + 12+ 32 + 112 = 158
Tai sao phai duyet tu phai sang trai
vi he so cuoi cung a[n-1] tuong ung voi luy thua lon nhat
| Vòng lặp | `a[i]` | `lt` | `a[i] * lt` | `res` |
|---|---:|---:|---:|---:|
| i = 4 | 7 | 1 | 7 | 7 |
| i = 3 | 4 | 2 | 8 | 15 |
| i = 2 | 3 | 4 | 12 | 27 |
| i = 1 | 1 | 8 | 8 | 35 |
| i = 0 | 0 | 16 | 0 | 35 |

luu y: bang tren dang tinh theo cach cong he so voi luy thua tang dan tu 0, nen ket qua cuoi cung phis duoc doi chieu lai voi cong thuc da thuc 158. De tinh dung theo cong thuc, ta can bat dau lt = 1 ow he so cuoi nhung phai cap nhat cah gan he so tuong ung.
    */
    //bai 7
    // ktao();
    // int TC; cin>>TC;
    
    // while(TC--){
    //     int n; cin>>n;
    //     int a[n];
    //     for(int i =0; i< n; i++){ cin>> a[i];}
    //     for(int i =0; i< n; i++){
    //         if(f[a[i]]){
    //             cout<< a[i] << ' ';
    //         }
    //     }
    //     cout<<endl;
    // }
    //bai 8
    // int TC; cin>>TC;
    // while(TC--){
    //     int n; cin>>n;
    //     int a[n];
    //     for(int i =0; i< n; i++){
    //         cin>>a[i];
    //     }
    //     int min_val = a[0], res = -1e9;
    //     for(int i = 1; i < n; i++){
    //         if(a[i] > min_val){
    //             res = max(res, a[i] - min_val);
    //         }
    //         min_val = min(a[i], min_val);
    //     }
    //     if(res == - 1e9) cout<<"-1\n";
    //     else cout<<res<<endl;
    // }
    /*
    Maximum Difference in Array
    doan code nay giai toan tim hieu lon nhat giua hai phan tu trong mang, voi dieu kien phan tu dung truoc phai nho hon phan tu tu dung sau.
    cu the:
    max(a[j] - a[i]) voi i < j, a[j] > a[i]
    neu ko ton tai cap thoai man thi in -1
    Giai thich cac bien: TC= so luong test case, n= so phan tu trong mang, a[] = mang dau vao, min_val = gia tri nho nhat da gap truoc vi tri hien tai, res = hieu lon nhat tim duoc
    Phan tich thuat toan qua vi du: 
    1
6
7 1 5 3 6 4
ta can tim hieu lon nhat: a[j] - a[i], j < i
Giai thich hai dong quan trong nhat
dong 1: tim hieu lon nhat
if(a[i] > min_val) res = max(res, a[i] - min_val)
tai sao phai co dieu kien a[i] > min_val
vi de bai yeu cau gia tri phia sau lon hon gia tri phia truoc
vd: 7 1 5 3 6 4
khi a[i] = 5, gia tri nho nhat la 1, 5 -1 = 4
ta cap nhat res = 4
dong 2: cap nhat gia tri nho nhat, min_val = min(a[i], min_val);
dong nay co y nghia neu a[i] nho hon min_val, cap nhat min_val, neu khong giua nguyen min_val
duyet den so 1: min(7,1) = 1
duyet den so 5: min(1,5) = 1
do phuc tap la O(n) cho moi test case.
    */
    //bai 9
    // int TC; cin>>TC;
    // while(TC--){
    //     int n, k; cin>> n>>k;
    //     int a[n];
    //     for(int i=0; i< n; i++) cin>>a[i];
    //     int sum =0;
    //     for(int i =0; i< n; i++) sum += a[i];
    //     int res = sum, idx = 0;
    //     for(int i =k; i< n; i++){
    //         sum = sum - a[i - k] + a[i];
    //         if(sum > res){
    //             res = sum;
    //             idx = i -k + 1;
    //         }
    //     }
    //     for(int i=0; i< k; i++){
    //         cout<<a[idx + i] <<" ";
    //     }
    //     cout<<endl;
    // }
    /*
    doan code nay su dung ky thuat sliding window(cua so truot) de tim doan con lien tiep co do dai k va tong lon nhat trong mang.
    sau do, chuong trinh in ra cac phan tu thuoc doan con do
    vd:
    1
7 3
2 1 5 1 3 2 8
trong do n = 7: mang co 7 phan tu
k = 3: Tim doan lien tiep gom 3 phan tu.
a[] = {2,1,5,1,3,2,8}
ta can tim doan co tong lon nhat
b1: khoi tao cua so dau tien
for(int i =0; i< k; i++) sum += a[i]
cua so dau tien:[2,1,5] 1 3 2 8
sum = 2 + 1 + 5 =8
ban dau: res =8, idx = 0;
b2: truot cua so
day la dong quan trong nhat:
sum = sum - a[i-k] +a[i];
y tuong: 1.bo phan tu dau tien cua cua so cu, 2. them phan tu tiep theo vao cua so moi
VD: lan 1: i = 3
cua so cu: [2,1,5] 1 3 2 8
bo 2, them 1: sum = 8 - 2 + 1 = 7
cua sno moi: 2[1, 5, 1] 3 2 8
lan 2: i = 4
bo 1, them 3: sum = 7 - 1 + 3 =9
cua so moi: 2 1 [5,1,3] 2 8
vi 9 > 8, cap nhat
res = 9; idx = 2;
lan 3: i = 5
sum = 9 - 5 + 2 = 6
lan 4: i=6
sum = 6 - 1 + 8 = 13
cap nhat: res = 13; idx = 4;
cua so cuoi cung: 2 1 5 1 [3,2,8]
bang tap hop
| Vị trí bắt đầu | Các phần tử | Tổng | res |
|---|---|---:|---:|
| 0 | 2, 1, 5 | 8 | 8 |
| 1 | 1, 5, 1 | 7 | 8 |
| 2 | 5, 1, 3 | 9 | 9 |
| 3 | 1, 3, 2 | 6 | 9 |
| 4 | 3, 2, 8 | 13 | 13 |
ket qua la 3 2 8
giai thich hai bien quan trong
sum: tong cua cua so hien tai
idx: vi tri dau cbua cua so co tong lon nhat
vd: idx = 4 co nghia la cua sno tot nhat bat dau tai a[4]
khi in: 
for(int i = 0; i< k; i++) cout<< a[idx + i] << ' ';
ta in ra: a[4] a[5] a[6]
do phuc tap la O(n)
kien thuc can nho;
sliding window dac biet huu ich khi de bai yeu cau:
tim tong lon nhat cua k phan tu lien tiep
Tim tong nho  nhat cua k phan tu lien tiep
Tim con lien tiep co do dai co dinh
Tim trung binh lon nhat cua nk phan tu lien tiep
Diem cot loi la thay vi tinh lai tong k phan tu o moi lan lap O((n*k)), chi can tru phan tu roi khoi cua so vaf cong phhan tu moi vao O(n).
    */ 
    //bai 10
    int TC; cin>>TC;
    while(TC--){
        int n; cin>>n;
        int a[n];
        for(int i =0; i< n; i++){
            cin>> a[i];
        }
        vector<int> v(a, a+n); //copy noi dnung mang a cho vector v
        sort(v.begin(), v.end());
        for(int i =0; i< n; i++){
            auto it = upper_bound(v.begin(), v.end(), a[i]);
            if(it == v.end()) cout<<" _ ";
            else cout<< (*it) << " ";
        }
        cout<<endl;
    }
    /*
    doan code nay su dung vector + sorting + binary search (upper_bound) de tim phan tu nho nhat trong mang nhung phai lon hon phan tu hien tai
    neu khong ton tai phan tu nao nho ho thi in_
    Giai thich tung phan
    b1: copy mang vao vector
    vector<int> v(a, a+n);
    cau lenh nay sao chep toan bo du lieu tu a sang vector v.
    vd: a = {5,2,8,3,10}, copy khi v= {5,2,8,3,10};
    luu y: a +n la dia chi ngay sau phan tu cuoi cung cua mang
    b2:Sap xep tang dan
    sort(v.begin(), v.end());
    tai sao phai sap xep, vi upper_bound hoat dong tren day da duoc sap xep
    b3: tim phan tu lon hon bang upper_bound
    auto it = upper_bound(v.begin(), v.end(), a[i]);
    day la phan quan trong nhat. upper_bound() tim vi tri dau tien co gia tri lon hon nghiem ngat gia tri can tim.
    vd: v = {2,3,5,8,10};
    auto it= upper_bound(v.begin(), v.end(), 5);
    ta co: 8 it tro den phan tu 8
    muon lay vi tri tai vi tri do , su dung *it = 8
    b4: Kiem tra iterator
    if(it ==  v.end()) cout<<' _ ';
    else cout<< *it << " ";
    co hai truong hop:
    tr1: ko tim thay vd: upper_bound(v.begin(), v.end(), 10); ko co so nao lon hon 10 thi it == end() in _
    tr2: tim thay upper_bound(v.begin(), v.end(), 5); tim duoc 8, nen in ra 8
    chay chuong trinh: 1
5
5 2 8 3 10
sau khi sap xep v = {2,3,5,8,10}
| i | a[i] | upper_bound tìm | Kết quả |
|---|---:|---:|---:|
| 0 | 5 | 8 | 8 |
| 1 | 2 | 3 | 3 |
| 2 | 8 | 10 | 10 |
| 3 | 3 | 5 | 5 |
| 4 | 10 | Không có | _ |
phan biet lower_bound va upper_bound, day la hai ham rat quan trong trong c++
vector<int> v = {1,2,4,5,6,7,8};
| Hàm | Ý nghĩa | Tìm với giá trị 2 | Kết quả |
|---|---|---|---|
| `lower_bound()` | Phần tử đầu tiên >= 2 | 2 | 2 |
| `upper_bound()` | Phần tử đầu tiên > 2 | 3 | 3 |
auto it1 = lower_bound(v.begin(), v.end(), 2);
auto it2 = upper_bound(v.begin(), v.end(), 2);

cout << *it1 << endl; // 2
cout << *it2 << endl; // 3

do phuc tap thuat toan
| Thao tác | Độ phức tạp |
|---|---|
| Copy mảng sang vector | O(n) |
| Sort | O(n log n) |
| upper_bound mỗi lần | O(log n) |
| upper_bound n lần | O(n log n) |
O(n log n)

    */




    return 0;
}