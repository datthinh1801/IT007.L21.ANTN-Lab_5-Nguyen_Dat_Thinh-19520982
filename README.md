# IT007.L21.ANTN-Lab_5-Nguyen_Dat_Thinh-19520982
## 5.4.3
Nhận xét kết quả chạy
```
└─$ ./5.4.3
x = x = 22
x = 3
x = 4
x = 5
x = 6
x = 7
x = 8
x = 9
x = 10
x = 11
x = 12
x = 13

x = 15
x = 16
x = 17
x = 18
x = 19
x = 0
x = 1
x = 2
x = 3
x = 4
x = 5
x = 6
x = 7
x = 8
x = 9
```

Ở đoạn kết quả trên, ta có thể thấy được rằng, ngay từ đầu giá trị của `x` đã bằng `2`, nghĩa là khi 2 threads chạy song song thì giá trị của `x` sẽ được `+ 1` hai lần nên `x` sẽ từ `0` tăng lên `2`.  

Tương tự ở dòng `x = 15`. Ở đây, `x` lại được cộng 2 lần cùng lúc nên `x` tăng từ `13` lên `15`.  
> Cần đồng bộ!
