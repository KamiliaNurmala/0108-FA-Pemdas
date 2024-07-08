/*! \mainpage Sistem Perhitungan Ujian Akhir
 *
 * \section intro_sec Pengatar
 * Selamat datang di dokumentasi SSistem Perhitungan Ujian Akhir
 * Sistem ini dirancang untuk menghitung nilai akhir mahasiswa
 *
 * \section structure_sec Struktur Kode
 * Kode ini terdiri dari 1 kelas utama dan 2 kelas turunan:
 * - \b MataKuliah: Mengelola matakuliah-matakuliah
 * - \b Pemrograman: Mengelola nilai presensi, activity, exercise, dan tugas akhir
 * - \b Jaringan: Mengelola nilai activity, dan exercise
 *
 * \section setup_sec Setup dan Konfigurasi
 * Untuk menjalankan sistem ini, pastikan Anda memiliki compiler yang mendukun stanndar C++11 atau lebih tinggi.
 * Kompilasi dan jalankan file ini menggunakan compiler pilihan Anda.
 *
 * \section author_sec Tentang Pengembang
 * Sistem ini dikembangkan oleh kamilianurmala.id sebagai bagian dari inisiatif untuk meningkatkan manajemen sumber daya dalam perusahaan
 *
 * \section note_Sec Catatan
 * Dokumentasi ini dihasilkan menggunakan Doxygen. Pastikan untuk mengikuti komentar yang disediakan dalam kode untuk pemahaman yang lebih baik
 */

/**
 * @file UCP3.cpp
 * @brief Sistem Sistem Perhitungan Ujian Akhir
 */

#include <iostream>
using namespace std;

/**
 * @class MataKuliah
 * @brief Kelas untuk menangani matakuliah yang terkait
 */
class MataKuliah
{
private:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

public:
    MataKuliah()
    {
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;
    }

    virtual void namaMataKuliah() { return; }
    virtual void inputNilai() = 0;
    virtual void hitungNilaiAkhir() { return; }
    virtual void cekKelulusan() { return; }

    void setPresensi(float nilai)
    {
        this->presensi = nilai;
    }

    float getPresensi()
    {
        return presensi;
    }

    void setActivity(float nilai)
    {
        this->activity = nilai;
    }

    float getActivity()
    {
        return activity;
    }

    void setExercise(float nilai)
    {
        this->exercise = nilai;
    }

    float getExercise()
    {
        return exercise;
    }

    void setTugasAkhir(float nilai)
    {
        this->tugasAkhir = nilai;
    }

    float getTugasAkhir()
    {
        return tugasAkhir;
    }
};

/**
 * @class Pemrograman
 * @brief Kelas untuk mengelola nilai-nilai matakuliah pemrograman
 */
class Pemrograman : public MataKuliah
{

private:
    float pPresensi;
    float pActivity;
    float pExercise;
    float pTugasAkhir;
    float pNilaiAkhir;

public:
    void inputNilai()
    {
        cout << "Masukkan nilai presensi : ";
        cin >> pPresensi;
        cout << "Masukkan nilai activity : ";
        cin >> pActivity;
        cout << "Masukkan nilai exercise : ";
        cin >> pExercise;
        cout << "Masukkan nilai tugas akhir : ";
        cin >> pNilaiAkhir;

        setPresensi(pPresensi);
        setActivity(pActivity);
        setExercise(pExercise);
        setTugasAkhir(pTugasAkhir);
    }

    void hitungNilaiAkhir()
    {
        pNilaiAkhir = (pActivity + pExercise + pTugasAkhir) / 3;
    }

    void cekKelulusan()
    {
        if (pNilaiAkhir >= 75)
        {
            cout << "Selamat anda dinyatakan Lulus" << endl;
        }
        else
        {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
};

/**
 * @class Jaringan
 * @brief Kelas untuk mengelola nilai-nilai matakuliah
 */
class Jaringan : public MataKuliah
{

private:
    float activity;
    float exercise;
    float nilaiAkhir;

public:
    void inputNilai()
    {

        cout << "Masukkan nilai activity : ";
        cin >> activity;
        setActivity(activity);
        cout << "Masukkan nilai exercise : ";
        cin >> exercise;
        setExercise(exercise);
    }

    void hitungNilaiAkhir()
    {
        nilaiAkhir = (activity + exercise) / 2;
    }

    void cekKelulusan()
    {
        if (nilaiAkhir >= 75)
        {
            cout << "Selamat anda dinyatakan Lulus" << endl;
        }
        else
        {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
};

int main()
{
    char pilih;
    MataKuliah *mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    while (true)
    {
        try
        {
            cout << "\nPilih Mata Kuliah" << endl;
            cout << "1. Pemrograman" << endl;
            cout << "2. Jaringan" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilih : ";
            cin >> pilih;

            switch (pilih)
            {
            case '1':
                mataKuliah = &pemrograman;
                mataKuliah->inputNilai();
                mataKuliah->hitungNilaiAkhir();
                mataKuliah->cekKelulusan();
                break;
            case '2':
                mataKuliah = &jaringan;
                mataKuliah->inputNilai();
                mataKuliah->hitungNilaiAkhir();
                mataKuliah->cekKelulusan();
                break;
            case '3':
                return 0;
            default:
                break;
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered" << endl;
        }
    }

    return 0;
}