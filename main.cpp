#include <iostream>

using namespace std;

#include "json.hpp"
// 201402
int main()
{
    cout << "Hello World!" << endl;
    cout << __cplusplus << endl;

    std::string j2 = R"(
                     {
                     "happy": true,
                     "pi": 3.141,
                     "params":{"ratio":1}
                     }
                     )";

    cout << j2 << endl;
    nlohmann::json j = nlohmann::json::parse(j2.c_str());

    std::cout << j.dump(4) << std::endl;

    cout << j["pi"] << endl;
    cout << j["params"]["ratio"]<< endl;

    std::string params_str0 = R"(
                              {
                              "template_name":"STRATEGY_TEST",
                              "template_params":
                              [

                              {"multiplier":
                              {"type":"double","min":0.01,"max":10}
                              },

                              {"ratio":
                              {"type":"double","min":0.01,"max":100}
                              }

                              ]

                              }
                              )";

    std::string params_str1 = R"(
                              {



                              "multiplier":
                              {"type":"double","min":0.01,"max":10}
                              ,

                              "ratio":
                              {"type":"double","min":0.01,"max":100}




                              }
                              )";
    std::string params_str = R"(
                             {
                             "multiplier":
                             {"QWidgetType":"QLineEdit","type":"double","min":0.01,"max":10}
                             ,
                             "ratio":
                             {"QWidgetType":"QLineEdit","type":"double","min":0.01,"max":100}
                             }
                             )";


    nlohmann::json jj = nlohmann::json::parse(params_str.c_str());
    std::cout << jj.dump(4) << std::endl;
    std::cout << "---------" << std::endl;

    nlohmann::json jparams = nlohmann::json::parse(params_str.c_str());
    std::cout << jparams.dump(4) << std::endl;

    // 使用迭代器输出
    for (nlohmann::json::iterator it = jparams.begin(); it != jparams.end(); ++it)
    {

        if (it->find("QWidgetType") != it->end())
        {
            std::cout << it.key() << " : " << it.value() << "\n";
        }
    }

    return 0;
}
