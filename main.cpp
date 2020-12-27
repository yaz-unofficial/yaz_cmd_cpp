#include <iostream>
#include <yazpp/zoom.h>
#include <algorithm>

using namespace ZOOM;
using namespace std;


int main(int argc, char* argv[]) {
//    std::cout << "Hello, World!" << std::endl;
//    std::cout << argc << std::endl;
    if
    (argc > 6)
    {
        std::string host(argv[1]);
//        std::cout << host << std::endl;
        int port = std::stoi(argv[2]);
//        std::cout << port << std::endl;
        std::string dbname(argv[3]);
//        std::cout << dbname << std::endl;
        std::string login(argv[4]);
//        std::cout << login << std::endl;
        std::string syntax(argv[5]);
//        std::cout << syntax << std::endl;
//        std::string escape(argv[6]);
//        std::string post_parse(argv[7]);
        std::string query1(argv[6]);
//        std::cout << query1 << std::endl;

//        std::cout << "host: " << host << ", port: " << port << ", dbname: "<< dbname << ", login: " << login << ", syntax: "  << syntax << ", query: " << query1 << std::endl;
        try {
//            std::cout << " make conn ";
            connection conn(host, port);
            conn.option("user", login);
            conn.option("databaseName", dbname);
            std::string syntaxlower(syntax);
            std::transform(syntaxlower.begin(), syntaxlower.end(), syntaxlower.begin(), ::tolower);
            conn.option("preferredRecordSyntax", syntaxlower);
//            std::cout << "conn ";

//        CCLQuery cclQuery();
            resultSet rs(conn, prefixQuery(query1));
//            std::cout << " conn " << std::endl;
//            CCLQuery cclQuery(query1, nullptr);
//            CCLQuery cclQuery("isbn=", &"3540591680");

            const record rec(rs, 0);
//            std::cout << "beginResults" << std::endl;
            std::cout << rec.render () << std::endl;
//            std::cout << "endResults" << std::endl;

        }
        catch(bib1Exception e){
            std::cout << "bib1Exception" << e.errmsg();

        }
        catch(systemException e){
            std::cout << "systemException";
        }
        catch(queryException e){
            std::cout << "queryException";
        }
        catch(const char*){
            std::cout << "char* ";
        }


    }
    else if(argc == 3){
//        std::cout << "test" << std::endl;
        std::string teststr(argv[1]);
        if(teststr=="--test"){
            std::string host;
            int port;
            std::string dbname;
            std::string login;
            std::string syntax;
            std::string query1;

            int test = std::stoi(argv[2]);
            if(test ==1){
                host = "193.30.112.135";
                port = 9991;
                dbname = "HBZ01";
                login = "";
                syntax = "mab";
//                syntax = "usmarc";
                query1 = "Funktion";
                query1 = "comme";
            }
            else if(test == 2){
                host = "z3950n.bsz-bw.de";
                port = 20210;
                dbname = "swbtit";
                login = "";
                syntax = "usmarc";
                query1 = "Funktion";
            }
            try {
//                std::cout << " make conn ";
                connection conn(host, port);
                conn.option("databaseName", dbname);
                conn.option("preferredRecordSyntax", syntax);
                if(host == "sru.gbv.de"){

                    conn.option("user", login);
                }
                else {
                    conn.option("user", login);
                }

//                std::cout << "conn ";

//        CCLQuery cclQuery();
//                std::cout << query1 << std::endl;
                resultSet rs(conn, prefixQuery(query1));
//                std::cout << " conn " << std::endl;
//            CCLQuery cclQuery(query1, nullptr);
//            CCLQuery cclQuery("isbn=", &"3540591680");

//                std::cout << rs.size() << std::endl;
//                std::cout << "beginResults" << std::endl;
//                for(int num = 0; num < 10; num++){
//                    std::cout << num << std::endl;
//                    const record rec(rs, num);
//                    std::string str= rec.render();
//                    std::cout << str << std::endl;
//                }
                const record rec(rs, 0);
                std::string str= rec.render();
                std::cout << str << std::endl;
//                std::cout << str << std::endl;

//                std::string substr = str.substr(199,3);
//
//                std::cout << substr << std::endl;
//
//                for(int i = 0; i< substr.length(); i++){
//				 std::cout << int(substr[i]) << " ,, ";
//
//				 //std::cout << substr[1];
//				 }
//                std::cout << std::endl;

//                std::string str= rec.render();
//                std::cout << str << std::endl;
//                std::string substr = str.substr(275,275);
//                std::string substr2 = substr.substr(17,5);
//                 //std::cout << str << std::endl;
//                 std::cout << substr2 << std::endl;
//                 for(int i = 0; i< substr2.length(); i++){
//				 std::cout << int(substr2[i]) << " ,, ";
//
//				 //std::cout << substr[1];
//				 }
//				 std::cout << std::endl;
//				 substr2 = str.substr(318,15);
//				 std::cout << substr2 << std::endl;
//				 for(int i = 0; i< substr2.length(); i++){
//				 std::cout << int(substr2[i]) << " ,, ";
//
//				 //std::cout << substr[1];
//				 }
//                std::cout << std::endl;
//                substr2 = str.substr(434,12);
//                std::cout << substr2 << std::endl;
//                for(int i = 0; i< substr2.length(); i++){
//                    std::cout << int(substr2[i]) << " ,, ";
//
//                    //std::cout << substr[1];
//                }
//				 std::cout << std::endl;
//                std::cout << "endResults" << std::endl;

            }
            catch(bib1Exception e){
                std::cout << "bib1Exception" << " --" << e.errmsg() << "-- " << e.addinfo();

            }
            catch(systemException e){
                std::cout << "systemException";
            }
            catch(queryException e){
                std::cout << "queryException";
            }
            catch(const char*){
                std::cout << "char* ";
            }
        }
    }
    else{
        std::cout << "Not enough arguments";
    }

    return 0;
}
