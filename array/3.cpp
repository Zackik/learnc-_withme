#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b ==0) return a;
    return gcd(b, a %b);
}
const int maxn = 1000000;
int a[maxn];
map<int, int> mp;
void solve(int n){
    for(int i =1 ; i<=sqrt(n); i++){
        if(n % i == 0){
            mp[i]++;
            if(i != n /i) mp[n /i]++;
        }
    }
}

int main(){
    //bai 11
    // int t; cin>>t;
    // while(t--){
    //     int n; cin>>n;
    //     for(int i=0; i<n; i++){
    //         cin>>a[i];
    //         solve(a[i]);
    //     } 
        int res = 1;
        // for(int i =0; i< n; i++){
        //     for(int j = i+ 1; j <n; j++){
        //         res = max(res, gcd(a[i], a[j]));
        //     }
        // }
        // cout<<res <<endl;
    //     for(auto it : mp){
    //         if(it.second >= 2){
    //             res = it.first;
    //         }
    //     }
    //     cout<<res <<endl;
    //     mp.clear();
    // }
    /*
    input: 1
5
12 18 24 30 36
ta xet tat ca cac cap
(12,18) 6
(12,24) 12
(12,30) 6
(12, 36) 12
(18,24) 6
(18,30) 6
(18,36) 18
(24,30) 6
(24,36) 12
(30,36) 6
GCD lon nhat la 18
phan tich do phuc tap
co hai vong lap long nhau: vong i chay toi da n lan, vong j chay cac phan tu phia sau i
Ham GCD su dung thuat toan Euclid:  O(logA), voi A la gia tri lon nhat trong mang.
Do phuc tap: Time complexity: O(n^2 * logA)
Space complexity: O(n) cho mang du lieu
Ban chat thuat toan
Bai nay co the hieu don gian: 1. chon mot phan tu a[i]
2.chon mot phan tu phia sau a[i], tuc la a[j]
3.Tinh GCD cua hai phan tu
4.So sanh voi ket qua lon nhat tai res.
5.Lap lai cho den khi xet het cac cap

Diem quan trong can nho
res = max(res,gcd(a[i], a[j]))
Day la thao tac tim gia tri lon nhat trong cac ket qua GCD, khong phia phep nhan hay phep cong.


Cach 2: map
Dang chuyen tu cach giai duyet tat ca cac cap phan tu de tim GCD lon nhat sang phuong thuc khac: dem so lan xuat hien cua tung uoc(divisor) bang map
phan tich solve(n) 
void solve(int n){
    for(int i =0; i<= sqrt(n); i++){
        if(n % i == 0) {
            mp[i] ++;
            if(i != n /i) mp[n/i] ++;
        }
    }
}
    muc dich la tim tat ca cac uoc cua n va tang so xuat hien cua chung trong map
    VD:
     solve(12)
     1, 2, 3, 4, 6, 12
     | Key (ước) | Value (số lần xuất hiện) |
|---|---:|
| 1 | 1 |
| 2 | 1 |
| 3 | 1 |
| 4 | 1 |
| 6 | 1 |
| 12 | 1 |
Neu n = 16, uoc 4 se bi bo qua neu chi dung <
y nghia cua map
map luu du lieu theo dang key --> value
trong bai nay: uoc cua mot so, value: so luong phan tu trong mang chia het cho uoc do
vd: 12 18 24
sau khi goi: for(int i =0; i<n; i++){
    solve(a[i])
}
    | Ước | Các số chia hết | Số lượng |
|---|---|---:|
| 1 | 12, 18, 24 | 3 |
| 2 | 12, 18, 24 | 3 |
| 3 | 12, 18, 24 | 3 |
| 4 | 12, 24 | 2 |
| 6 | 12, 18, 24 | 3 |
| 8 | 24 | 1 |
| 9 | 18 | 1 |
| 12 | 12, 24 | 2 |
| 18 | 18 | 1 |
| 24 | 24 | 1 |
phan tich doan tim ket qua
 int res =1;
 for(auto it : mp){
    if(it.second >= 2){
        res = it.first;
    }
 }
    int res = 1;

for (auto it : mp) {
    if (it.second >= 2) {
        res = max(res, it.first);
    }
}
    tai sao thuat toan nay tim duoc GCD lon nhat
    3
12 18 24
ta xet uoc 6: 12 chia het 6
18 chia het 6
24 chia het cho 6
vay mp[6] = 3
fieu nay co nghia ton tai it nhat hai so trong mang cung chia het cho 6
tuong tu voi mp[12] = 2, vi 12 va 24 deu chia het cho 12
khi tim uoc lon nhat co lan xuat tu 2 tro len, ta thu duoc: 12
do chinh la GCD lon nhat cua mot cap phan tu trong mang (cap 12 va 24).
so sanh hai phuong phap
| Tiêu chí | Duyệt từng cặp + GCD | Đếm ước bằng map |
|---|---|---|
| Ý tưởng | Xét từng cặp số | Đếm số lần xuất hiện của ước |
| Độ phức tạp | O(n² log A) | O(n√A log D) với `map` |
| Cấu trúc dữ liệu | Mảng | Mảng + map |
| Độ khó | Dễ hiểu | Cần hiểu về ước số |

trong do n; so luong phan tu, A: gia tri lon nhat trong mang, d: so luong uoc khac nhau duoc luu trong map
mot kien thuc quan trong nen nho: 
neu mot uoc d xuat hien it nhat hai lan trong qua trinh phan tich cac phan tu, dieu do co nghia la ton tai it nhat hai phan tu khac nhau cung deu chia het cho d. Do do
ta can tim GCD lon nhat bang cach tim uoc lon nhat co tan suat it nhat 2.
Day la cach tu duy rat huu ich competitive programming lien quan den GCD, divisor vaf frequency counting.

    */
    //bai 12
    // int t; cin>>t;
    // while(t--){
    //     int n; cin>>n;
    //     for(int i = 0; i< n; i++){
    //         cin>> a[i];
    //     }
    //     int res =0;
    //     for(int i =0; i< n; i++){
    //         res = gcd(res, a[i]);
    //     }
    //     if(res == 1){
    //         cout<< 0 <<endl;
    //         continue;
    //     }
    //     int ans = 1;
    //     for(int i = 2; i <= sqrt(res); i++){
    //         if(res % i ==0){
    //             ++ans;
    //             if(i != res /i) ++ans;
    //         }
    //     }
    //     cout<< ans <<endl;
    // }
    /*
    code nay dang su dung mot huong tuu duy khac. Tim GCD cua toan bo mang sau do dem so uoc GCD do (ko tinh uoc 1).
    Phan tich
    tim GCD cua toan bo mang
    int res =0;
    for(int i =0; i<n; i++) res = gcd(res, a[i]);
    y tuong: ban dau res =0
    moi lan lap, lay gcd cua res va phan tu hien tai. sau do duyet het, res chinh la GCD cua tat ca phan tu.
    vd: n = 4, a = [12,24,36,48]
    ta co
    | Lần lặp | a[i] | res trước | gcd(res, a[i]) |
|---|---:|---:|---:|
| 1 | 12 | 0 | 12 |
| 2 | 24 | 12 | 12 |
| 3 | 36 | 12 | 12 |
| 4 | 48 | 12 | 12 |
ket qua res = 12
tai sao bat dau tu 0?
gcd(0,x) = x
do do, phan tu dau tien se duoc dua vao res ma khong can xu ly rieng
kiem tra gcd bang 1
if( res == 1){
    cout<<0<<endl;
    continue;
    }
    neu gcd cua toan bo mang bang 1 thi khong ton tai uoc chung lon hon 1.
    vd: a=[6,10,15]
    ta co: gcd(6,10,15) = 1
    cac so khong co uoc chung nao lon hon 1
    vi vay, chuong trinh in 0 va chuyen sang test tiep theo.
    dem so luong uoc cua gcd
    day la phan quan trong nhat:
    int ans = 1;
    for(int i= 2; i <= sqrt(res); i++){
        if(res % i ==0){
            ++ans;
            if( i != res /i) ++ans;
        }
    }
        muc dich dem uoc cua res, nhung ko tinh uoc 1
        vd: res = 12
        cac uoc cua 12 = 1,2,3,4,6,12
        | i | 12 % i | Có phải ước? | ans |
|---|---:|---|---:|
| 2 | 0 | Có, thêm 2 và 6 | 3 |
| 3 | 0 | Có, thêm 3 và 4 | 5 |
ban dau int ans = 1;
tai sao lai bang 1
vi khong tinh uoc 1, nhung van can dem chinh res
sau vong lap: ans = 5
ket qua {2,3,4,6,12}
tai sao phai co dieu kien i != res /i
if(i != res /i) ++ ans;
de tranh dem trung res la so chinh phuong
vd: res = 36
ta co 36 = 6 * 6
neu khong kiem tra dieu kien, khi i =6, chuong trinh se dem so 6 hai lan.
vi vay giup tranh truong hop do
so sanh hai huong giai vua hoc
| Tiêu chí | Phương pháp 1 | Phương pháp 2 |
|---|---|---|
| Cách làm | Tìm GCD lớn nhất của một cặp | Tìm GCD toàn bộ mảng |
| Sử dụng | `gcd(a[i], a[j])` | `gcd(res, a[i])` |
| Độ phức tạp | O(n² log A) | O(n log A + √A) |
| Mục đích | Tìm GCD lớn nhất của hai phần tử | Đếm ước của GCD toàn mảng |
Luu y quan trong: hai phuong phap giai hai bai toan khac nhau, khong the thay the cho nhau.
pp1: tim gcd lon nhat giua hai phan tu bat ky
pp2: dem so uoc lon hon 1 cua gcd cua toan bo mang
nen nam chac su khac biet giua gcd(a[i], a[j]) va gcd(res, a[i]), vi day la tu duy rat quan trong trong bai toan gcd cua competitive programming.

    */
    //bai 13: diem can bang (equilibrium index)
    // int t; cin>>t;
    // while(t--){
    //     int n; cin>>n;
    //     for(int i =0; i<n; i++) cin>>a[i];
    //     long long sum =0;
    //     for(int i =0; i< n; i++) sum += a[i];
    //     long long left =0;
    //     bool ok = false;
    //     for(int i=0; i<n ; i++){
    //         sum -=a[i];
    //         if(sum == left){
    //             cout<< i << " ";
    //             ok = true;
    //         }
    //         left += a[i];
    //     }
    //     if(!ok) cout<<"-1\n";
    //     else cout<<endl;
    // }
    /*
    code nay dang giai bai toan tim vi tri can bang trong mang
    y tuong: tim nhung vi tri i sao cho tong cac phan tu ben trai bang tong cac phan tu ben phai, khong tinh phan tu tai vi tri i.
    1.phan tich y tuong
    long long summ =0;
    long long left =0;
    sum: tong tat ca phan tu trong mang
    left: tong cac phan tu nam ben trai vi tri hien tai i
    tong ben phai duoc tinh bang: right = sum - left - a[i]
    dieu kien vi tri can bang: left = right
    hay left = sum - left - a[i]
    phan tich tung doan code
    b1: tinh tong mang
    long long sum =0;
    for(int i =0; i< n; i++) sum += a[i];
    a = [1,3,5,2,2]
    ta co saum: 1 + 3+ 5 + 2 + 2 = 13
    b2: khoi tao bien left
    long long left =0;
    bool ok = false;
    ban dau, khi dung o vi tri dau tien, khong co phan tu nao ben trai.
    do do: left =0
    ok dung de kiem tra co tim duoc vi tri can bang hay khong
    b3: duyet mang
    for(int i =0; i< n; i++){
        sum -= a[i];
        if(sum == left){
            cout<<i<<" ";
            ok = true;
        }
        left += a[i];
    }
        day la phan quan trong nhat.
        1.loai bo phan tu hien tai khoi sum: sum -= a[i];
        luc nay sum chinh la tong cac phan tu ben phai
        2.kiem tra: if(sum == left) neu tong ben trai bang tong ben phai thi tim duoc vi tri can bang
        3.cap nhat tong ben trai: left += a[i]; chuan bi cho lan lap tiep theo
        3.vd chay tung buoc
        input: 1
5
1 3 5 2 2
ban dau : sum = 13
left = 0
| i | a[i] | sum sau khi trừ a[i] | left trước khi cập nhật | Kiểm tra |
|---|---:|---:|---:|---|
| 0 | 1 | 12 | 0 | 12 != 0 |
| 1 | 3 | 9 | 1 | 9 != 1 |
| 2 | 5 | 4 | 4 | 4 == 4 |
| 3 | 2 | 2 | 9 | 2 != 9 |
| 4 | 2 | 0 | 11 | 0 != 11 |
tai vi tri i =2
[1,3] |5| [2,2]
tong ben trai: 1 + 3=4
tong ben phai: 2+ 2 = 4
do phuc tap 
| Thành phần | Độ phức tạp |
|---|---|
| Tính tổng mảng | O(n) |
| Duyệt tìm vị trí cân bằng | O(n) |
| Tổng thời gian | O(n) |
| Bộ nhớ phụ | O(1) |
mot cach tu duy can ghi nho
khi giai bai toan chia mang thanh hai phan bang nhau, ko nhat thiet phai tao hai mang
chi can ghi nho: right = total - left - current
va kiem tra left = right
day la ky thuat prefix sum ket hop voi tong hoan toan mang, rat thuong gap trong competitive programming.
meo: hay chu y thu tu sum-=a[i] kiem tra left += a[i]. neu cap nhat left truoc khi kiem tra, vo tinh tinh ca phan u hien tai vao ben trai.
     */
     //bai 14: tan suat le
    //  int t; cin>>t;
    //  while(t--){
    //     int n; cin>>n;
    //     for(int i =0; i< n; i++) cin>>a[i];
    //     int ans = a[0];
    //     for(int i = 1; i< n; i++){
    //         ans ^= a[i];
    //     }
    //     cout<<ans<<endl;
    //  }
    //bai 15: loai bo meo
    // int t; cin>>t;
    // while(t--){
    //     int n;cin>>n;
    //     for(int i =0; i< n; i++){
    //         cin>>a[i];
    //     }
    //     int res = 1, dem =1;
    //     for(int i= 1; i< n; i++){
    //         if(a[i] == a[i-1]){
    //             ++dem;
    //         }
    //         else{
    //             dem =1;
    //         }
    //         res = max(res, dem);
    //     }
    //     cout<<n - res<<endl;
    // }
    /*
    code dang thuc hien tim do dai lon nhat cua mot doan cac phan tu lien tiep co gia tri bang nhau (longest consecutive equal elements).
    giai thich thuat toan
    dem: dem so phan tu lien tiep giong nhau hien tai
    res: luu so luong phan tu lien tiep giong nhau
    vd: n = 7
    a ={1,1,2,2,2,3,3}
    | i | a[i] | a[i-1] | dem | res |
|---|---|---|---|---|
| 1 | 1 | 1 | 2 | 2 |
| 2 | 2 | 1 | 1 | 2 |
| 3 | 2 | 2 | 2 | 2 |
| 4 | 2 | 2 | 3 | 3 |
| 5 | 3 | 2 | 1 | 3 |
| 6 | 3 | 3 | 2 | 3 |

ket qua: res = 3, n - res = 7 -3 = 4
do phuc tap cap nhat do dai lon nhat sau moi lan kiem tra
thoi gian O(n)-duyet mang mot lan
bo nho O(n)-luu mang
luu y: cong thuc n-res co y nghia phu thuoc vao yeu cau de bai. Thuat toan tren tim doan lien tiep dai nhat co cac phan tu bang nhau. Neu gui de bai goc, co ther giai thich tai sao phai in n - res

    */
    //bai 16: sap xep mang
    // int t; cin>>t;
    // while(t--){
    //     int n,m; cin>>n>>m;
    //     for(int i =0; i< n; i++) cin>>a[i];
    //     int pos[101] = {0};
    //     for(int i=0; i< m; i++){
    //         int x; cin>>x;
    //         pos[x - 1] = 1;
    //     }
    //     for(int i =0; i< n; i++){
    //         if(pos[i] == 0) continue;
    //         int index = i;
    //         while(index < n && pos[index]){
    //             ++index;
    //         }
    //         //[i, index]
    //         sort(a+i, a + index + 1);
    //         i = index;
    //     }
    //     bool ok = true;
    //     for(int i =0; i< n -1; i++){
    //         if(a[i] > a[i +1]){
    //             ok = false;
    //             break;
    //         }
    //     }
    //     if(ok) cout<< "YES\n";
    //     else cout<< "NO\n";
    // }
    /*
    code dang giai quyet mot bai toan lien quan den sap xep cac doan con cua mang dua tren nhung vi tri duoc danh dau.
    Giai thich tung phan
    mang pos[] int pos[101] = {0}, day la mang danh dau vi tri
    vd: N = 6, M = 3, x = 1 2 4
    pos[0] = 1, pos[1]=1, pos[2] =1
    | Index | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| pos | 1 | 1 | 0 | 1 | 0 | 0 |
tai sao lai dung x -1:
vi de bai thuong danh so vi tri tu 1, trong khi mang c++ danh so tu 0
vd: vt1: index0, vt2: index1, vt4, index3
b.tim doan lien tiep duoc danh dau
for(int i =0; i<n; i++){
    if(pos[i] == 0) continue;
    int index =i;
    while(index < n && pos[index]) ++index;
}
y tuong pos[i] == 0 bo qua
neu pos[i] == 1; bat dau tim vi tri lien tiep co gia tri 1
inde chay den khi pos[index] == 0 hoac het mang
pos ={1,1,0,1,1,1,0}
 | i | index | Giải thích |
|---|---|---|
| 0 | 0 | Bắt đầu đoạn |
| 0 | 1 | pos[1] = 1 |
| 0 | 2 | pos[2] = 0, dừng |
doan dau tien la [0,1]
doan thu hai: [3,5]
sort doan con
sort(a+i, a + index + 1)
day la phan quan trong
hha, sort() su dung khoang: sort(begin, end)
trong do begin: vi tri bat dau
end: vi tri ket thuc nhung khong bao gom phan tu tai do
vd: int a[] = {5,4,3,2,1}
sort(a + 1, a + 4)
Kiem tra mang da tang dan chua
bool ok = true;
for(int i=0; i< n; i++){
    if(a[i] > a[i + 1]){
        ok = false;
        break;
    }
}
    neu toan tai a[i] > a[i + 1] thi mang chua duoc xep sap tang dan
    mot so diem can chu y trong code
    i = index, sau khi vong for tang i++, vong lap se tiep tuc tu index + 1. Dieu nay khong sai trong truong hop tai vi index la vi tri dau tien khong duoc danh dau. TUy nhien, no bo qua viec kiem tra pos[index] o vong lap ke tiep. Neu muon code de hieu hon, co the viet i=index -1
    vi vong for se tu dong tang i them 1
    ngoai ra: pos[101] chi an toan neu n <= 101 va cac vi tri x nam trong pham vi hop le
ban chat thuat toan
dang ket hop 3 ky thuat
| Kỹ thuật | Mục đích |
|---|---|
| Mảng đánh dấu (Marking Array) | Xác định vị trí được phép xử lý |
| Two Pointers | Tìm đoạn liên tiếp được đánh dấu |
| Sorting | Sắp xếp từng đoạn |
| Linear Scan | Kiểm tra mảng tăng dần |
do phuc tap:
tim cac doan: O(n)
sap xep toi da O(n log n)
kiem tra O(n)
tong the O(n log n)
 
can nho nhat cach hoat dong cua sort(a +i, a + index);
day la ky thuat rat quan trong trong cac bai toan xu ly doan con (subarray) cua c++.

    */
    
    return 0;
}