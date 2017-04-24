#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
int main()
{
    try{
       // std::ifstream ifs("output", std::ios::binary);

        std::ifstream ifs;

        ifs.open ("output", std::ifstream::in);

        std::string dest;
        boost::iostreams::filtering_ostream out;
        out.push(boost::iostreams::gzip_compressor());
       // out.push(boost::iostreams::file_sink("test1"));
        out.push(boost::iostreams::back_inserter(dest));
        //boost::iostreams::write(out, "hello", 5);

        boost::iostreams::filtering_streambuf<boost::iostreams::output> compress_out;  
        boost::iostreams::copy(ifs, out);
        //boost::iostreams::copy(std::stringstream("hello"), out);
        //std::cout << "dest:" << dest << std::endl;
        boost::iostreams::filtering_istream in;
        in.push(boost::iostreams::gzip_decompressor());
        //in.push(boost::iostreams::file_source("test.txt"));
        std::stringstream ss(dest);
        in.push(ss);
        char text[100] = {0};
        boost::iostreams::read(in, text, 10);
        //boost::iostreams::copy(in, std::stringstream(text));
        std::cout << "text:" << text << std::endl;
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