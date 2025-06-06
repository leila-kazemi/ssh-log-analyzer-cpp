#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int main() {
    std::ifstream logfile("sample-auth.log");
    if (!logfile.is_open()) {
        std::cerr << "فایل لاگ باز نشد. مطمئن شو که sample-auth.log در مسیر درست قرار داره.\n";
        return 1;
    }

    std::map<std::string, int> ip_counts;
    std::string line;

    // خط به خط لاگ رو می‌خونیم
    while (std::getline(logfile, line)) {
        if (line.find("Failed password") != std::string::npos) {
            std::istringstream iss(line);
            std::string word;
            std::string ip;
            while (iss >> word) {
                if (word == "from") {
                    iss >> ip;
                    ip_counts[ip]++;
                    break;
                }
            }
        }
    }

    logfile.close();

    std::ofstream report("suspicious_ips.txt");
    if (!report.is_open()) {
        std::cerr << " نتونستم فایل گزارش رو بنویسم.\n";
        return 1;
    }

    report << " آی‌پی‌هایی که چند بار تلاش ناموفق داشتن:\n\n";
    bool found = false;

    for (const auto& entry : ip_counts) {
        if (entry.second >= 2) {
            found = true;
            report <<  entry.first << " → " << entry.second << " بار تلاش ناموفق\n";
        }
    }

    if (!found) {
        report << "هیچ آی‌پی مشکوکی پیدا نشد.\n";
    }

    report.close();
    std::cout << " بررسی کامل شد. نتایج در فایل suspicious_ips.txt ذخیره شد.\n";
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int main() {
    std::ifstream logfile("sample-auth.log");
    if (!logfile.is_open()) {
        std::cerr << " فایل لاگ باز نشد. مطمئن شو که sample-auth.log در مسیر درست قرار داره.\n";
        return 1;
    }

    std::map<std::string, int> ip_counts;
    std::string line;

    // خط به خط لاگ رو می‌خونیم
    while (std::getline(logfile, line)) {
        if (line.find("Failed password") != std::string::npos) {
            std::istringstream iss(line);
            std::string word;
            std::string ip;
            while (iss >> word) {
                if (word == "from") {
                    iss >> ip;
                    ip_counts[ip]++;
                    break;
                }
            }
        }
    }

    logfile.close();

    std::ofstream report("suspicious_ips.txt");
    if (!report.is_open()) {
        std::cerr << " نتونستم فایل گزارش رو بنویسم.\n";
        return 1;
    }

    report << " آی‌پی‌هایی که چند بار تلاش ناموفق داشتن:\n\n";
    bool found = false;

    for (const auto& entry : ip_counts) {
        if (entry.second >= 2) {
            found = true;
            report << "📌 " << entry.first << " → " << entry.second << " بار تلاش ناموفق\n";
        }
    }

    if (!found) {
        report << "هیچ آی‌پی مشکوکی پیدا نشد.\n";
    }

    report.close();
    std::cout << " بررسی کامل شد. نتایج در فایل suspicious_ips.txt ذخیره شد.\n";
    return 0;
}
