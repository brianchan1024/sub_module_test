#include <iostream>
#include <string>
#include <vector>
#include "absl/strings/str_join.h"

#include <iostream>
#include <fstream>
#include "json/json.h" // or jsoncpp/json.h , or json/json.h etc.
#include <glog/logging.h>
#include <gflags/gflags.h>

using namespace std;

void json_example() {
    ifstream ifs("alice.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings
    cout << "Book: " << obj["book"].asString() << endl;
    cout << "Year: " << obj["year"].asUInt() << endl;
    const Json::Value& characters = obj["characters"]; // array of characters
    for (int i = 0; i < characters.size(); i++){
        cout << "    name: " << characters[i]["name"].asString();
        cout << " chapter: " << characters[i]["chapter"].asUInt();
        cout << endl;
    }
}

DEFINE_string(confPath, "test.conf", "program configure file.");
DEFINE_int32(port, 1111, "program listen port");
DEFINE_bool(debug, true, "run debug mode");

int main(int argc,char* argv[]) {
  google::InitGoogleLogging(argv[0]); //初始化 glog
  cout << argv[0] << endl;
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_log_dir = "./log";
  LOG(INFO) << "Hello,GOOGLE!";
  cout << "confPath = " << FLAGS_confPath << endl;
  cout << "port = " << FLAGS_port << endl;
  std::vector<std::string> v = {"foo","bar","baz"};
  std::string s = absl::StrJoin(v, "-");

  std::cout << "Joined string: " << s << "\n";
  json_example();
  return(0);
}

