#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/read.hpp>
#include <boost/iostreams/filter/gzip.hpp>
int main()
{
    try{
       // std::ifstream ifs("output", std::ios::binary);

        std::ifstream ifs;

        ifs.open ("output", std::ifstream::in);
 std::vector<char>  temp, dest;
     
        boost::iostreams::filtering_ostream out;
        out.push(boost::iostreams::gzip_compressor());
        out.push(boost::iostreams::file_sink("test4.gz"));
        //out.push(boost::iostreams::back_inserter(dest));
        boost::iostreams::write(out, "c1esba\n2222a\n4rratasfd", 20);

        //boost::iostreams::filtering_streambuf<boost::iostreams::output> compress_out;  
       // boost::iostreams::copy(ifs, out);
        //boost::iostreams::copy(std::stringstream("hello"), out);
        //std::cout << "dest:" << dest << std::endl;
        //out.clear();
        boost::iostreams::filtering_istream in;
         std::stringstream ss_decomp;  
        in.push(boost::iostreams::gzip_decompressor());
        in.push(boost::iostreams::file_source("testz.gz"));
        //std::stringstream ss(dest);
      //  in.push(ss);
      std::string str;
char strs[20];
//boost::iostreams::copy(in, std::cout);
std::cout << "text\n";
      boost::iostreams::read(in,strs,20);
        char text[100];std::cout << "text11:"<<strs;

    }
    catch(std::exception& e)
    {
    std::cout << "exception:" << e.what() << std::endl;
    }
    catch(...)
    {
    std::cout << "unknown exception." << std::endl;
    }
    //system("pause");
    return 0;
}