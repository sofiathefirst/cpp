#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
using std::string;
 void FastGzipString(const string& uncompressed, string* compressed) {
  boost::iostreams::filtering_ostream out;
  out.push(
      boost::iostreams::gzip_compressor(boost::iostreams::zlib::best_speed));
  out.push(boost::iostreams::back_inserter(*compressed));
  boost::iostreams::write(out,
                          reinterpret_cast<const char*>(uncompressed.data()),
                          uncompressed.size());
}

 void FastGunzipString(const string& compressed, string* decompressed) {
  boost::iostreams::filtering_ostream out;
  out.push(boost::iostreams::gzip_decompressor());
  out.push(boost::iostreams::back_inserter(*decompressed));
  boost::iostreams::write(out, reinterpret_cast<const char*>(compressed.data()),
                          compressed.size());
}


int main()
{
    try{
    

    std::ifstream ifs;

        ifs.open ("output", std::ifstream::in);
 std::vector<char>  temp, dest;
     
        boost::iostreams::filtering_ostream out;
        out.push(boost::iostreams::gzip_compressor());
        out.push(boost::iostreams::file_sink("testz.gz"));
        //out.push(boost::iostreams::back_inserter(dest));
        boost::iostreams::write(out, "3c1esba\n2222a\n4rratasfd", 20);

        //boost::iostreams::filtering_streambuf<boost::iostreams::output> compress_out;  
       // boost::iostreams::copy(ifs, out);
        //boost::iostreams::copy(std::stringstream("hello"), out);
        //std::cout << "dest:" << dest << std::endl;
        //out.clear();
        boost::iostreams::close(out, std::ios_base::out);
        boost::iostreams::filtering_ostream in;
         std::stringstream ss_decomp;  
        in.push(boost::iostreams::gzip_decompressor());
        in.push(boost::iostreams::file_sink("testz.txt"));
        char text[100];
 boost::iostreams::write(in,boost::iostreams::file_source("testz.gz"));



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