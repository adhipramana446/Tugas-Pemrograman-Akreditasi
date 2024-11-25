#include <stdio.h>
#include <string.h>

int main (){
    float nilai1, nilai2, nilai3, nilai4, nilai5, nilai6, nilai7;

    printf("=== Sistem Penilaian Akreditasi Program Studi Magister/Magister Terapan ===\n");

    // Khalis 51
    // Fira 69
    // Faiq 54

    // fungsi kecukupan jumlah DTPS
    int ndtps;

    printf("\n-- Penilaian berdasarkan kecukupan jumlah dosen tetap (DTPS) --\n");
    printf("Masukkan jumlah dosen tetap (tidak boleh 0): ");
    scanf("%d", &ndtps);

    if (ndtps >= 6) {
        nilai1 = 4;
    } else if (ndtps >= 3 && ndtps < 6) {
        nilai1 = (2 * ndtps) / 3; 
        if (nilai1 <= 2 && nilai1 > 0) {
            nilai1 = 2;
        }
    } else {
        nilai1 = 0;
    }
    printf("Nilai kecukupan jumlah DTPS = %.2f\n", nilai1);

    // fungsi jabatan akademik DTPS
    int ndgb, ndlk;
    float pgblk;

    printf("\n-- Penilaian berdasarkan jabatan akademik dosen tetap (DTPS) --\n");
    printf("Masukkan jumlah dosen tetap yang memiliki jabatan Guru Besar: ");
    scanf("%d",  &ndgb);
    printf("Masukkan jumlah dosen tetap yang memiliki jabatan Lektor Kepala: ");
    scanf("%d", &ndlk);

    pgblk = ((ndgb + ndlk) / ndtps) * 100;

    if (pgblk >= 70) {
        nilai2 = 4;
    } else {
        nilai2 = (float) 2 + ((20 * pgblk) / 7); 
        if (nilai2 < 2) {
            nilai2 = 2;
        }
    }
    printf("Nilai jabatan akademik DTPS = %.2f\n", nilai2);

    // fungsi kurikulum
    int A, B, C;

    printf("\n-- Penilaian berdasarkan kurikulum --\n");
    printf("Masukkan nilai keterlibatan pemangku kepentingan dalam proses evaluasi dan pemutakhiran kurikulum (0-4): ");
    scanf("%d", &A);
    printf("Masukkan nilai kesesuaian capaian pembelajaran dengan profil lulusan dan jenjang KKNI/SKKNI (0-4): ");
    scanf("%d", &B);
    printf("Masukkan nilai ketepatan struktur kurikulum dalam pembentukan capaian pembelajaran (0-4): ");
    scanf("%d", &C);

    nilai3 = (float) (A + (2 * B) + (2 * C)) / 5;
    if (nilai3 < 1) {
        nilai3 = 1;
    }
    printf("Nilai kurikulum = %.2f\n", nilai3);

    // fungsi kesesuaian bidang kerja
    int pbs;

    printf("\n-- Penilaian berdasarkan kesesuaian bidang kerja lulusan saat mendapatkan pekerjaan pertama (PBS) --\n");
    printf("Masukkan presentase nilai kesesuaian bidang kerja lulusan saat mendapatkan pekerjaan pertama (0-100): ");
    scanf("%d", &pbs);

    if (pbs >= 60) {
        nilai4 = 4;
    } else {
        nilai4 = (20 * pbs) / 3;
        if (nilai4 > 4) {
            nilai4 = nilai4 / 100; // bagi '100' agar hasil tidak lebih dari '4.00'
        }  
    }
    printf("Nilai PBS = %.2f\n", nilai4);

    // fungsi kepuasan pengguna
    int a, b, c, d;
    float tki;

    printf("\n-- Penilaian berdasarkan tingkat kepuasan pengguna terhadap lulusan prodi --\n");
    printf("Masukkan presentase jawaban 'sangat baik': ");
    scanf("%d", &a);
    printf("Masukkan presentase jawaban 'baik': ");
    scanf("%d", &b);
    printf("Masukkan presentase jawaban 'cukup': ");
    scanf("%d", &c);
    printf("Masukkan presentase jawaban 'kurang': ");
    scanf("%d", &d);

    tki = (float) (4 * a) + (3 * b) + (2 * c) + d;
    nilai5 = tki / 100; // ubah jadi bagi '100' agar hasil tidak lebih dari '4.00'

    printf("Nilai kepuasan pengguna = %.2f\n", nilai5);

    // fungsi publikasi ilmiah mahasiswa
    int na1, na2, na3, na4, nb1, nb2, nb3, nc1, nc2, nc3, nm;
    float rl, rn, ri;

    printf("\n--  Penilaian Berdasarkan Jumlah Publikasi Ilmiah Mahasiswa Magister --\n");
    printf("Masukkan jumlah publikasi jurnal nasional tidak terakreditasi: ");
    scanf("%d", &na1);
    printf("Masukkan jumlah publikasi jurnal nasional terakreditasi: ");
    scanf("%d", &na2);
    printf("Masukkan jumlah publikasi jurnal internasional: ");
    scanf("%d", &na3);
    printf("Masukkan jumlah publikasi jurnal internasional bereputasi: ");
    scanf("%d", &na4);
    printf("Masukkan jumlah publikasi seminar wilayah/lokal/PT: ");
    scanf("%d", &nb1);
    printf("Masukkan jumlah publikasi seminar nasional: ");
    scanf("%d", &nb2);
    printf("Masukkan jumlah publikasi seminar internasional: ");
    scanf("%d", &nb3);
    printf("Masukkan jumlah tulisan di media massa wilayah: ");
    scanf("%d", &nc1);
    printf("Masukkan jumlah tulisan di media massa nasional: ");
    scanf("%d", &nc2);
    printf("Masukkan jumlah tulisan di media massa internasional: ");
    scanf("%d", &nc3);
    printf("Masukkan jumlah mahasiswa pada saat TS: ");
    scanf("%d", &nm);

    rl = ((float)(na1 + nb1 + nc1) / nm) * 100;
    rn = ((float)(na2 + na3 + nb2 + nc2) / nm) * 100;
    ri = ((float)(na4 + nb3 + nc3) / nm) * 100;

    if (ri >= 2) {
        nilai6 = 4;
    } else if (ri < 2 && rn >= 20) {
        nilai6 = 3 + (ri / 2);
    } else if (ri > 0 && ri < 2 && rn > 0 && rn < 20) {
        nilai6 = 2 + (2 * (ri / 2)) + (rn / 20) - ((ri * rn) / (2 * 20));
    } else if (ri == 0 && rn ==  0 && rl >= 70) {
        nilai6 = 2;
    } else if (ri == 0 && rn == 0 && rl < 70) {
        nilai6 = (2 * rl) / 70;
    } else {
        nilai6 = 0;
    }
    printf("Nilai publikasi ilmiah = %.2f\n", nilai6);

// Fungsi Publikasi Ilmiah Mahasiswa Magister Terapan
    int naa1, naa2, naa3, naa4, nbb1, nbb2, nbb3, ncc1, ncc2, ncc3, nmm;
    float rll, rnn, rii;

    printf("\n--  Penilaian Berdasarkan Jumlah Publikasi Ilmiah Mahasiswa Magister Terapan --\n");
    printf("Masukkan jumlah publikasi jurnal nasional tidak terakreditasi: ");
    scanf("%d", &naa1);
    printf("Masukkan jumlah publikasi jurnal nasional terakreditasi: ");
    scanf("%d", &naa2);
    printf("Masukkan jumlah publikasi jurnal internasional: ");
    scanf("%d", &naa3);
    printf("Masukkan jumlah publikasi jurnal internasional bereputasi: ");
    scanf("%d", &naa4);
    printf("Masukkan jumlah publikasi seminar wilayah/lokal/PT: ");
    scanf("%d", &nbb1);
    printf("Masukkan jumlah publikasi seminar nasional: ");
    scanf("%d", &nbb2);
    printf("Masukkan jumlah publikasi seminar internasional: ");
    scanf("%d", &nbb3);
    printf("Masukkan jumlah tulisan di media massa wilayah: ");
    scanf("%d", &ncc1);
    printf("Masukkan jumlah pagelaran/pameran/presentasi mahasiswa dalam forum tingkat wilayah: ");
    scanf("%d", &ncc2);
    printf("Masukkan jumlah pagelaran/pameran/presentasi mahasiswa dalam forum tingkat nasional: ");
    scanf("%d", &ncc3);
    printf("Masukkan jumlah mahasiswa pada saat TS: ");
    scanf("%d", &nmm);

    rll = ((float)(naa1 + nbb1 + ncc1) / nmm) * 100;
    rnn = ((float)(naa2 + naa3 + nbb2 + ncc2) / nmm) * 100;
    rii = ((float)(naa4 + nbb3 + ncc3) / nmm) * 100;

    if (rii >= 2) {
        nilai7 = 4;
    } else if (rii < 2 && rnn >= 20) {
        nilai7 = 3 + (rii / 2);
    } else if (rii > 0 && rii < 2 && rnn > 0 && rnn < 20) {
        nilai7 = 2 + (2 * (rii / 2)) + (rnn / 20) - ((rii * rnn) / (2 * 20));
    } else if (rii == 0 && rnn ==  0 && rll >= 70) {
        nilai7 = 2;
    } else if (rii == 0 && rnn == 0 && rll < 70) {
        nilai7 = (2 * rll) / 70;
    } else {
        nilai7 = 0;
    }
    printf("Nilai publikasi ilmiah = %.2f\n", nilai7);

    // fungsi akumulasi skor akhir dan grade
    float skor_akhir;
    char grade[30];
    
    skor_akhir = (nilai1 + nilai2 + nilai3 + nilai4 + nilai5 + nilai6 + nilai7) / 7;

    if (skor_akhir >= 3.61){
        strcpy(grade, "Unggul");
    } else if (skor_akhir >= 3.01 && skor_akhir < 3.61){
        strcpy(grade, "Baik Sekali");
    } else if (skor_akhir >= 2.00 && skor_akhir < 3.01){
        strcpy(grade, "Baik");
    } else {
        strcpy(grade, "Tidak Terakreditasi");
    }

   // rangkuman output
    printf("\n\n== BERIKUT RANGKUMAN PENILAIAN AKREDITASI ==\n");
    printf("\nNilai kecukupan jumlah DTPS = %.2f\n", nilai1);
    printf("Nilai jabatan akademik DTPS = %.2f\n", nilai2);
    printf("Nilai kurikulum = %.2f\n", nilai3);
    printf("Nilai PBS = %.2f\n", nilai4);
    printf("Nilai kepuasan pengguna = %.2f\n", nilai5);
    printf("Nilai publikasi ilmiah magister = %.2f\n", nilai6);
    printf("Nilai publikasi ilmiah magister terapan = %.2f\n", nilai7);
    printf("\nSkor Akhir = %.2f (%s)\n", skor_akhir, grade);
    printf("\n== TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI! ==\n");

    return 0;
    
}
