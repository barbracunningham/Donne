#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <list>
#include <map>
#include<array>
#include<tuple>
#include<cassert>
#include<queue>
#include<bitset>

#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <functional>
#include <curl/curl.h>

#include <opencv2/opencv.hpp>
#include <omp.h>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using std::string;
using namespace std;
using namespace cv;

class Donne
{
public:
    Donne();
    Donne(const std::string &ip, const std::string &db, const std::string &user, const std::string &pass);
    ~Donne();
    auto select_query(const std::string &table, const std::string &field, const int &rowstart, const int &rowend) -> int;
    auto download() -> int;
    auto dimensions(int d1, int d2, int s1, int s2) -> int;
    auto override_threshold(int t) -> void;
    auto override_corethread(int t) -> void;
private:
    class Download;
    Download *dwnl__;
    class SQLDatabase;
    SQLDatabase *sqld__;
};

class Donne::SQLDatabase
{
public:
    SQLDatabase();
    SQLDatabase(const std::string &sql_ip, const std::string &sql_db, const std::string &sql_user, const std::string &sql_pass);
    ~SQLDatabase();
    auto select(const std::string &sql_table, const std::string &sql_field, const int &rowstart, const int &rowend) -> int;
    sql::Driver *dri__;
    sql::Connection *con__;
    sql::Statement *stmt__;
    sql::ResultSet *res__;
    sql::PreparedStatement *prestmt__;
    std::vector<std::string> url_store;
};

class Donne::Download
{
public:
    CURL *curlhandle__;
    FILE *filehandle__;
    CURLcode response;
    std::vector<std::string> urls;
    int count {0};
    Download();
    ~Download();
    static auto cv_write(char *ptr__, size_t size, size_t nmemb, void *userdata__) -> size_t;
    auto cv_download(const char *imurl__) -> cv::Mat
    auto cv_conduit(std::string &url) -> int;
    auto exe_download() -> void;
    auto format_url(std::vector<std::string> &X) -> void;
    int d_1 {0};
    int d_2 {0};
    float s_1 {0};
    float s_2 {0};
    int threshold {5};
};
