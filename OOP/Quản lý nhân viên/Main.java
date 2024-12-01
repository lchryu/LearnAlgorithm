import java.util.ArrayList;
import java.util.Scanner;

abstract class NhanVien {
    protected String hoTen;
    protected float luong;

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ho ten: ");
        hoTen = sc.nextLine();
    }

    public void xuat() {
        System.out.println("Ho ten: " + hoTen);
        System.out.println("Luong: " + luong);
    }

    // Abstract method for calculating salary
    public abstract void tinhLuong();
}

class NhanVienVanPhong extends NhanVien {
    private float luongCoBan;
    private int soNgayLamViec;

    @Override
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap luong co ban: ");
        luongCoBan = sc.nextFloat();
        System.out.print("Nhap so ngay lam viec: ");
        soNgayLamViec = sc.nextInt();
    }

    @Override
    public void tinhLuong() {
        luong = luongCoBan * soNgayLamViec;
    }

    @Override
    public void xuat() {
        super.xuat();
        System.out.println("Luong co ban: " + luongCoBan);
        System.out.println("So ngay lam viec: " + soNgayLamViec);
    }
}

class NhanVienSanXuat extends NhanVien {
    private int soSanPham;
    private float tienCong1SP;

    @Override
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so san pham: ");
        soSanPham = sc.nextInt();
        System.out.print("Nhap tien cong 1 san pham: ");
        tienCong1SP = sc.nextFloat();
    }

    @Override
    public void tinhLuong() {
        luong = soSanPham * tienCong1SP;
    }

    @Override
    public void xuat() {
        super.xuat();
        System.out.println("So san pham: " + soSanPham);
        System.out.println("Tien cong 1 san pham: " + tienCong1SP);
    }
}

class CongTy {
    private ArrayList<NhanVienVanPhong> NVVP = new ArrayList<>();
    private ArrayList<NhanVienSanXuat> NVSX = new ArrayList<>();

    public void themNhanVienVanPhong(NhanVienVanPhong nv) {
        NVVP.add(nv);
    }

    public void themNhanVienSanXuat(NhanVienSanXuat nv) {
        NVSX.add(nv);
    }

    public void xuatTatCaNhanVien() {
        System.out.println("Nhan vien van phong:");
        for (NhanVienVanPhong nv : NVVP) {
            nv.xuat();
        }
        System.out.println("Nhan vien san xuat:");
        for (NhanVienSanXuat nv : NVSX) {
            nv.xuat();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        CongTy congTy = new CongTy();
        Scanner sc = new Scanner(System.in);

        System.out.println("Nhap so nhan vien van phong: ");
        int soNVVP = sc.nextInt();
        sc.nextLine();  // Consume newline

        for (int i = 0; i < soNVVP; i++) {
            NhanVienVanPhong nvvp = new NhanVienVanPhong();
            nvvp.nhap();
            nvvp.tinhLuong();
            congTy.themNhanVienVanPhong(nvvp);
        }

        System.out.println("Nhap so nhan vien san xuat: ");
        int soNVSX = sc.nextInt();
        sc.nextLine();  // Consume newline

        for (int i = 0; i < soNVSX; i++) {
            NhanVienSanXuat nvsx = new NhanVienSanXuat();
            nvsx.nhap();
            nvsx.tinhLuong();
            congTy.themNhanVienSanXuat(nvsx);
        }

        congTy.xuatTatCaNhanVien();
    }
}
