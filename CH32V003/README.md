# CH32RISC_DNG



## Bắt đầu dự án (Getting Started)

Để bắt đầu làm việc với dự án này, hãy làm theo các bước sau:

1. **Kiểm tra sơ đồ mạch**: Xem trong thư mục `hardware/` để biết sơ đồ chân (pinout).
2. **Cài đặt môi trường**:
Bạn có thể lựa chọn một trong hai môi trường phát triển sau:
- **MounRiver Studio**: Tải và cài đặt tại [mounriver.com](http://www.mounriver.com/). (Dành cho người thích dùng IDE trọn gói).
- **PlatformIO**: Cài đặt thông qua tiện ích mở rộng trên VS Code tại [platformio.org](https://platformio.org/). 
    - Xem hướng dẫn cấu hình cho dòng WCH CH32 tại: [WCH CH32 PlatformIO](https://registry.platformio.org/platforms/platformio/wch-ch32) hoặc [nhấn vào đây để xem Hướng dẫn phát triển](#hướng-dẫn-phát-triển)
3. **Mở dự án**: Import thư mục này vào IDE và tiến hành biên dịch thử.
4. **Phối hợp**: Nếu bạn muốn đóng góp tính năng mới, hãy tạo một Issue hoặc gửi Merge Request từ một nhánh phụ.

## Thêm tệp của bạn

* [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) hoặc [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
* [Thêm tệp bằng dòng lệnh](https://docs.gitlab.com/topics/git/add_files/#add-files-to-a-git-repository) hoặc đẩy kho lưu trữ git đã có bằng lệnh sau:

```
cd existing_repo
git remote add origin https://gitlab.com/nguyennguyen.okai1/edng/ch32risc_dng.git
git branch -M main
git push -uf origin main
```

## Cộng tác

* [Mời các thành viên nhóm và cộng tác viên](https://docs.gitlab.com/ee/user/project/members/)
   - **Mời thành viên**: Admin sẽ cấp quyền `Developer` cho các thành viên liên quan đến dự án này.
* [Quy trình gộp mã](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
   - Mọi thay đổi phải được thực hiện trên một nhánh phụ.
   - Code chỉ được gộp vào `main` sau khi dự án hoàn thành và được quản lý duyệt.
* [Tự động đóng các vấn đề liên quan đến hợp nhất](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
* [Cho phép phê duyệt yêu cầu hợp nhất](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
* [Thiết lập tự động hợp nhất](https://docs.gitlab.com/user/project/merge_requests/auto_merge/)

## Kiểm thử và triển khai

Use the built-in continuous integration in GitLab.

* [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/)
* [Analyze your code for known vulnerabilities with Static Application Security Testing (SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
* [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
* [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
* [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

## Tên dự án
Hướng dẫn phát triển chip CH32V003

## Mô tả chip CH32V003
Dòng giới thiệu: "Dự án này tập trung vào thiết kế phần cứng và phát triển firmware cho dòng chip CH32 sử dụng kiến trúc RISC-V."

Tính năng: 
Giao tiếp nối tiếp (Serial Communication):

    UART/USART: Hỗ trợ truyền/nhận dữ liệu để debug và giao tiếp với các module khác.
    I2C: Giao tiếp thành công với các cảm biến và màn hình OLED.
    SPI: Tối ưu hóa tốc độ cao cho việc đọc/ghi thẻ nhớ hoặc màn hình LCD màu.

Điều khiển và Xung (Timers & Signals):

    PWM: Điều khiển độ sáng LED hoặc tốc độ động cơ với tần số tùy chỉnh.
    GPIO: Cấu hình các chân vào/ra cơ bản, ngắt ngoài (External Interrupts).

Chuyển đổi tín hiệu:

    ADC: Đọc giá trị điện áp từ các cảm biến analog với độ phân giải 12-bit.
    DAC: Xuất tín hiệu điện áp tương tự.

Tính năng nâng cao:

    DMA: Tăng tốc độ truyền dữ liệu mà không gây tốn tài nguyên CPU.
    RTC: Quản lý thời gian thực cho các ứng dụng cần độ chính xác về giờ giấc.
Tài liệu tham khảo:
   
    CH32V003RM.PDF-http://www.wch-ic.com/downloads/CH32V003RM_PDF.html
    CH32V003DS0.PDF-http://www.wch-ic.com/downloads/CH32V003DS0_PDF.html
    QingKeV2_Processor_Manual.PDF-http://www.wch-ic.com/downloads/QingKeV2_Processor_Manual_PDF.html

## Hình ảnh
### - Sơ đồ khối

![Sơ đồ khối CH32V003](https://raw.githubusercontent.com/openwch/ch32v003/refs/heads/main/image/frame.jpg)
### - Sơ đồ chân
![Sơ đồ chân CH32V003](https://raw.githubusercontent.com/Tengo10/pinout-overview/main/pinouts/CH32v003/ch32v003f4p6.svg)
## Lộ trình
### Lộ trình phát triển (Roadmap)

   * Dưới đây là các mục tiêu phát triển tiếp theo cho dự án **CH32RISC_DNG**:

### Giai đoạn 1: Hoàn thiện ngoại vi cơ bản (Đang thực hiện)
- [x] Giao tiếp UART (Debug console).
- [x] Điều khiển GPIO và Ngắt ngoài.
- [ ] Cấu hình ADC để đọc cảm biến Analog.
- [x] PWM điều khiển độ sáng LED/Động cơ.

### Giai đoạn 2: Giao tiếp nâng cao & Lưu trữ
- [ ] Tích hợp thư viện FatFS cho thẻ nhớ SD Card qua SPI.
- [ ] Giao tiếp I2C với màn hình OLED 0.96 inch.
- [ ] Triển khai DMA để tối ưu hóa truyền dữ liệu UART/SPI.

### Giai đoạn 3: Tối ưu hóa & Phần cứng v2.0
- [ ] Thiết kế lại mạch PCB (v2.0) nhỏ gọn hơn.
- [ ] Viết bootloader tùy chỉnh qua USB-PD.
- [ ] Đóng gói thư viện để dễ sử dụng hơn.

## Hướng dẫn phát triển
* ### [Hướng dẫn phát triển và cài đặt môi trường](https://docs.google.com/document/d/1Hy_F4BAHvbE8takZp_mMzfyhN1uPVTfxNA2fuej7SZA/edit?tab=t.0)

## Tác giả và lời cảm ơn

### Tác giả chính
* **Tên của bạn** (Đào Trọng Khánh) - Thiết kế phần cứng và lập trình phụ.

### Lời cảm ơn
* Xin chân thành cảm ơn đội ngũ **WCH** đã cung cấp các tài liệu kỹ thuật và mẫu chip CH32V.
* Cảm ơn cộng đồng **OpenWCH** vì các thư viện mã nguồn mở hữu ích.

## Giấy phép
- Hãy nêu rõ cách thức cấp phép cho dự án đó

## Tình trạng dự án
* Đang phát triển