#include <bits/stdc++.h>
using namespace std;

int main(){
    //bai 17
//     int t; t =1;
// while (t--) {
//     int n, c;
//     cin >> n >> c;
//     int a[n];
//     for (int &x : a) cin >> x;
//     int cnt = 1;
//     for (int i = 1; i < n; i++) {
//         if (a[i] - a[i - 1] <= c) {
//             ++cnt;
//         }
//         else {
//             cnt = 1;
//         }
//     }
//     cout << cnt << endl;
// }
    /*
    code dang co y tuong dem so phan tu lien tiep thoa man dieu kien
    a[i] - a[i - 1] <=c
    giai thich tung phan
    cnt = 1 ban dau co mot phan tu
    i = 1: bat dau so sanh tu phan tu thu hai
    a[i] - a[i-1] <= c: kiem tra khoang cach giua hai phan tu lien
    ++cnt: neu thoa man, tang do dai doan lien tiep
    cnt= 1: neu khong thoa man, bat dau lai tu phan tu hien tai
    vd:
    1
5 2
1 2 3 7 8
| i | a[i-1] | a[i] | Hiệu | cnt |
|---|---:|---:|---:|---:|
| 1 | 1 | 2 | 1 | 2 |
| 2 | 2 | 3 | 1 | 3 |
| 3 | 3 | 7 | 4 | 1 |
| 4 | 7 | 8 | 1 | 2 |
    luu y quan trong, code hien tai in ra do dai lien tiep thoa man dieu kien ket thuc tai phan tu cuoi cung.
    Neu de bai yeu cau tim do dai doan lien tiep dai nhat, can them bien maccnt:

    */
    //bai 18: day con lien tuc nho nhat
    // int t ; cin>>t;
    // while(t--){
    //     int n, x; cin>>n>>x;
    //     int a[n];
    //     for(int &x : a) cin>>x;
    //     int left =0, res = 1e9;
    //     long long sum =0;
    //     for(int r= 0; r < n; r++){
    //         sum += a[r];
    //         while(sum > x){
    //             res = min(res, r -left + 1);
    //             sum -= a[left]; left++;
    //         }
    //     }
    //     if(res == 1e9) cout<<"-1\n";
    //     else cout<<res<<endl;
    // }
    /* code dang su dung ky thuat sliding window(cua so truot) de tim doan con lien tiep ngan nhat co tong lon hon x
    y tuong sliding window
    co 2 con tro: left: vi tri bat dau cua so
    r: vi tri ket thuc cua cua so
    cac bien: sum: tong cac phan tu trong cua so hien tai
    res: do dai doan con ngan nhat tim duoc
    nguyen tac:
    tang r de mo rong cua so
    cong a[r] vao sum
    neu sum > x, cua so da thoa man
    cap nhat ket qua bang min(res, r - left +1)
    loai bo a[left] va tang left de thu nho cua so
    lap lai cho den khi sum <= x
    vd:
    1
6 7
2 3 1 2 4 3
| Bước | left | r | Cửa sổ | sum | res |
|---|---:|---:|---|---:|---:|
| 1 | 0 | 0 | [2] | 2 | - |
| 2 | 0 | 1 | [2,3] | 5 | - |
| 3 | 0 | 2 | [2,3,1] | 6 | - |
| 4 | 0 | 3 | [2,3,1,2] | 8 | 4 |
| 5 | 1 | 3 | [3,1,2] | 6 | 4 |
| 6 | 1 | 4 | [3,1,2,4] | 10 | 4 |
| 7 | 2 | 4 | [1,2,4] | 7 | 4 |
| 8 | 2 | 5 | [1,2,4,3] | 10 | 4 |
| 9 | 3 | 5 | [2,4,3] | 9 | 3 |
| 10 | 4 | 5 | [4,3] | 7 | 3 |

do phuc tap
| Thành phần | Độ phức tạp |
|---|---|
| Duyệt `r` | O(n) |
| Duyệt `left` | O(n) |
| Tổng thời gian | **O(n)** |
| Bộ nhớ | O(n) |
mot luu y cuc ky quan trong
sliding window dang nay chi hoat dong dung khi cac phan tu trong mang kong am. neu mang co so am, viec tang left khong von bao dam sum giam, do do thuat toan co the sai ket qua
day la phan quan trong nhat cua thuat toan sliding window(cua so truot). minh se phan tich tung dong, sau do mo phong may tinh thuc hien 
de hieu
while(sum > k){
    res = min(res, r-left+1);
    sum -= a[left];
    left++;
}
    muc dich tong cac phan tu trong cua so lon hon x, chung ta co gang thu nho cua so de tim doan con ngan nhat

    co 3 thao tac:
    1.ghi nhan do dai doan con hien tai
    2.loai bo phan tu dau tien koi cua so
    3.di chuyen con tro left sang phai

    2.phan tich tung dong
    while(sum > k) kiem tra tong cua cua so co lon hon x hay khong
    vd: x =7
    sum =10
    vi 10 > 7, dk dung nen vong lap duoc thuc hien
    tai sao dung while thay vi if, chung ta muon thu nho cua so lien tuc cho den khi tong khong con lon hon x.
    res = min(res, r -left + 1) day la dong dung do dai doan con ngan nhat
    trong do: r: vi tri cuoi doan con
    left: vi tri doan con
    r - left + 1: do dai doan con
    res: do dai nho nhat tim duoc tu truoc den nay
    vd: left=1 r=4;
    doan con: Index:  0  1  2  3  4
Array:  2  3  1  2  4
           |--------|
    do dai: r - left + 1= 4 - 1+ 1=4
    gia su: res =5
    res = min(5,4); res = 4;
    tai sao phai dung min() vi chung ta muon giu lai do dai nho nhat
    | Đoạn con | Độ dài | res |
|---|---:|---:|
| Đoạn 1 | 5 | 5 |
| Đoạn 2 | 4 | 4 |
| Đoạn 3 | 3 | 3 |
| Đoạn 4 | 6 | 3 |
loai bo phan tu dau tien sum -= a[left] day la thao tac thu nho cua so
vd: a = {2,3,1,2,4,3}
left =0;
r = 4;
sum = 12;
cua so hien tai: [2,3,1,2,4]
sum -= a[left];
sum = 12 - 2
sum =10
cua so luc nay ve mat logic tro thanh {3,1,2,4}
left++;
vd: left =; left++;
Index:  0  1  2  3  4
Array: [2, 3, 1, 2, 4]
        ^
      left

Index:  0  1  2  3  4
Array:  2 [3, 1, 2, 4]
           ^
         left

mo phong toan bo vong while
a = {2,3,1,2,4,3} x =7
khi r =4, ta co
sum = 12; left=0; res =4;
dk: 12>7
cap nhat:
res = min(4,5)// res = 4
sum-=a[0] //sum =10
left++;
lan lap thu hai:
10>7//true
res = min(4,4); res =4
sum -= a[1]; sum =7
left++; left=2

cua so moi [1,2,4]
lan lap thu ba:
7>7//false
vong while ket thuc. Tai sao ket thuc tong lon hon 7, nhung cua so hien tai
chi co tong bang 7


so do tuy duy thuat toan
while right < 1: 
    cur_sum += nums[right]

    while cur_sum >= s:
        min_len = min(min_len, right - left + 1)
        cur_sum -= nums[left]
        left += 1
    right += 1

        sum > x ?
           |
       +---+---+
       |       |
      ĐÚNG    SAI
       |       |
  Cập nhật res |
       |       |
  Loại a[left] |
       |       |
   left++      |
       |       |
   Kiểm tra lại|
       |       |
       +-------+

dieu quan trong nhat can hieu
tai sao phai cap nhat res truoc khi xoa a[left]
boi vi tai thoi diem do, cua so van dang thoa man dieu kien sum > x
vd: [2,3,1,2,4]
tong = 12 >7// ta phai ghi nhan do dai 5 truoc bo so 2 dau tien
r++: mo rong cua so
left++: thu nho cua so
sum: theo doi tong cua so
res: luu do dai ngan nhat
day la tu duy cot loi cua sliding window, khi hieu duov hai thao tac mo rong va thu nho cua so, ban co the giai duoc
nhieu bai toan mang va chuoi bang ky thuat nay

    */
    return 0;
}