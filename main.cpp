#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include "single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

/*
    1. 创建如下的 json 对象：
    {
        "pi": 3.141,
        "happy": true,
        "name": "Niels",
        "nothing": null,
        "answer": {
            "everything": 42
        },
        "list": [1, 0, 2],
        "object": {
            "currency": "USD",
            "value": 42.99
        }
    }
*/
static void create_first_json()
{
    json j;
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = {1, 0, 2};
    j["object"] = {{"currency", "USD"}, {"value", 42.99}};

    json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {{"everything", 42}}},
        {"list", {1, 0, 2}},
        {"object", {{"currency", "USD"}, {"value", 42.99}}}};

    assert(j == j2);

    cout << j << endl;
}
/*
    2. 创建确定类型的对象
       json::array()  &  json::object()
*/
static void create_explicit_cases()
{
    json array_not_object = json::array({{"currency", "USD"}, {"value", 42.99}});
    cout << "array_not_object: " << array_not_object << endl;

    json empty_array_explicit = json::array();
    cout << "empty_array: " << empty_array_explicit << endl;

    json empty_object_implicit = json({});
    json empty_object_explicit = json::object();
    assert(empty_object_explicit == empty_object_implicit);
    cout << "empty_object: " << empty_object_implicit << endl;

    json null_object_implicit = json{};
    json null_object_explicit = json();
    assert(null_object_explicit == null_object_implicit);
    cout << "null_boject: " << null_object_implicit << endl;
}
/*
    3. 反序列化（from string to json）
       _json  &  json::parse()
*/
static json deserialize()
{
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;

    auto j2 = R"(
        {
            "happy": true,
            "pi": 3.141
        }
    )"_json;

    auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");

    assert(j == j2 && j == j3);

    cout << "deserialization: " << j << endl;
    return j;
}
/*
    4. 序列化（from json to string）
       j.dump() 接收参数为缩进量，重载 << 运算符调用了 dump()
       一般情况下无须特地调用 dump() 序列化，直接调用 << 即可，
       dump() 可看作主要用于格式化输出。
*/
static void serialize(const json &j)
{
    string s = j.dump();
    cout << "serialization: " << s << endl;

    cout << "serialization with pretty printing: " << j.dump(4) << endl;
}
/*
    5. 序列化 value 与原始 string 的区别
       serialized value: j_string  &  serialized_string
       original string: cpp_string  &  cpp_string2  &  j_string.get<std::string>()
*/
static void diff_serialization_and_assignment()
{
    json j_string = "this is a string";
    string serialized_string = j_string.dump();
    cout << "serialized value: " << j_string << " == " << serialized_string << endl;

    auto cpp_string = j_string.get<string>();
    string cpp_string2;
    j_string.get_to(cpp_string2);
    cout << "original string: " << cpp_string << " == " << cpp_string2 << " == " << j_string.get<string>() << endl;
}
/*
    6. 流序列化（一）
       from istream to json  &  from json to ostream
*/
static void interact_with_iostream()
{
    json j;
    cin >> j;

    // 重载 setw() 操纵器，同 j.dump(4)
    cout << setw(4) << j << endl;
}
/*
    7. 流序列化（二）
       from ifstream to json  &  from json to ofstream 
*/
static void interact_with_fstream()
{
    ifstream i("file.json");
    json j;
    i >> j;

    ofstream o("pretty.json");
    o << setw(4) << j << endl;
}
/*
    8. Read from iterator range
*/
static void interact_with_iterator()
{
    vector<uint8_t> v = {'t', 'r', 'u', 'e'};
    json j = json::parse(v.begin(), v.end());

    json j2 = json::parse(v);

    assert(j == j2);
    cout << j << endl;
}
/*
    9. 自定义类型的序列化
*/
namespace ns
{
struct person
{
    string name;
    string address;
    int age;

    bool operator==(const person &p) { return name == p.name && address == p.address && age == p.age; }
};

void to_json(json &j, const person &p)
{
    j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
}

void from_json(const json &j, person &p)
{
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("age").get_to(p.age);
}
} // namespace ns

static void arbitrary_type_convert()
{
    ns::person p{"Ned Flanders", "744 Evergreen Terrace", 60};

    // conversion: person -> json
    json j = p;
    cout << j << endl;

    // conversion: json -> person
    auto p2 = j.get<ns::person>();

    assert(p == p2);
}


int main()
{
    create_first_json();

    create_explicit_cases();

    json j = deserialize();
    serialize(j);

    diff_serialization_and_assignment();

    interact_with_iostream();

    interact_with_fstream();

    interact_with_iterator();

    arbitrary_type_convert();
}
