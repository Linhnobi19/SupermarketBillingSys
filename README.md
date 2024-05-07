Mô tả về chương trình Supermarket Billing system
Viết bằng C++ 
Với 1 chức năng
-	Add function để add sản phẩm 
-	Delete function
-	Create buyer state để mua hàng, food items, …

Đầu tiên về thiết lập các class
-	Class product
-	Class admin (duy nhất  use singleton)
-	Class shopping (để tạo ra giao diện và hiển thị)
-	Class receipt (để thanh toán hiển thị hóa đơn)

Về cấu hình của từng class
-	Product
Sẽ có 5 attributes là id, name, price, amount, discount
-	Hàm Recipt
Sẽ có code của recipt đấy, ngày mua hàng và 1 mảng để chứa item mà người đó mua và số lượng của item đó.
Về function thì cần có hàm để có thể lấy date
Hàm dùng để in thông tin hóa đơn dựa theo yêu cầu người mua
Và tôi muốn có thể lưu lại được hóa đơn thì lưu lại vào file khi mà thành công mua hàng.
-	Shopping
Đây là hàm chính để thực hiện việc bảo trì cx như mua sắm
Hàm menu() để hiện thị option để khi đăng nhập vào administrator hoặc buy product
Thì class sẽ có administror dùng để đăng nhập thôi
1 mảng product để lưu trữ danh sách hàng hiện có
1 mảng receipt để có thể thực hiện nhiệm vụ thanh toán hóa đơn
1 biến state để khẳng định rằng khi mà khởi động chương trình thì cần thực hiện đọc lại file cập nhật thêm thông tin mặt hàng
Để có  thể đăng nhập thì ta khai triển 1 hàm để biến kí tự nhập vào thành *
Khi vào administrator thì ta có thể add, remove, edit có mặt hàng
Khi để người mua vào thì ta cho người mua chọn lựa mặt hàng số hàng. Khi mua xong thì xuất hóa đơn. Nếu thành công thanh toán thì thì xuất hóa đơn lưu lại và cập nhật số lượng mặt hàng của quán  update lại vào file.

Mô tả hoạt động
Menu chính
![image](https://github.com/Linhnobi19/SupermarketBillingSys/assets/100674055/95bb6877-3709-4725-a3b4-20368fd18ed6)

Khi truy cập administrator
![image](https://github.com/Linhnobi19/SupermarketBillingSys/assets/100674055/7b72647a-d075-4e78-ad64-b6c71ecbf6f0)

Khi truy cập buyer menu
![image](https://github.com/Linhnobi19/SupermarketBillingSys/assets/100674055/b404e56b-7d87-4f49-9e02-d4ca025ab470)

Chuyển hướng sang thanh toán
![image](https://github.com/Linhnobi19/SupermarketBillingSys/assets/100674055/c3cb6469-5eaa-4a62-99bb-0cb761a559c1)
