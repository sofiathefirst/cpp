#include <boost/iostreams/filtering_stream.hpp>  
#include <boost/iostreams/copy.hpp>  
#include <boost/iostreams/filter/zlib.hpp>  
  
#include <boost/iostreams/device/file_descriptor.hpp>  
#include <boost/iostreams/device/file.hpp>  
  
#include <iostream>  
#include <sstream>  
int main()  
{  
    try{  
          
        std::stringstream ss_comp;  
        boost::iostreams::filtering_ostream out;  
        out.push(boost::iostreams::zlib_compressor());  
        //out.push(ss_comp);    //压缩到字符流中  
        out.push(boost::iostreams::file_sink("test.txt"));      //压缩到文件中  
        boost::iostreams::copy(std::stringstream("hello"), out);  
  
        std::cout << "compressor data:" << ss_comp.str() << std::endl;  
  
        std::stringstream ss_decomp;  
        boost::iostreams::filtering_istream in;  
        in.push(boost::iostreams::zlib_decompressor());  
        //in.push(ss_comp);     //从字符流中解压  
        in.push(boost::iostreams::file_source("test.txt"));     //从文件中解压  
        boost::iostreams::copy(in, ss_decomp);  
  
        std::cout << "decompressor data:" << ss_decomp.str() << std::endl;  
    }  
    catch(std::exception& e)  
    {  
        std::cout << "exception:" << e.what() << std::endl;  
    }  
    catch(...)  
    {  
        std::cout << "unknown exception." << std::endl;  
    }  
    system("pause");  
    return 0;  
}  