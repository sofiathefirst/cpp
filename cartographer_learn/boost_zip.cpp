
#include <cinttypes>
#include <cmath>
#include <string>
#include <iostream>

#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_stream.hpp>


using std::string;

inline void FastGzipString(const string& uncompressed, string* compressed) {
  boost::iostreams::filtering_ostream out;
  out.push(
      boost::iostreams::gzip_compressor(boost::iostreams::zlib::best_speed));
  out.push(boost::iostreams::back_inserter(*compressed));
  boost::iostreams::write(out,
                          reinterpret_cast<const char*>(uncompressed.data()),
                          uncompressed.size());
}

inline void FastGunzipString(const string& compressed, string* decompressed) {
  boost::iostreams::filtering_ostream out;
  out.push(boost::iostreams::gzip_decompressor());
  out.push(boost::iostreams::back_inserter(*decompressed));
  boost::iostreams::write(out, reinterpret_cast<const char*>(compressed.data()),
                          compressed.size());
}


int main()
{

    string un_str="123abcABC,.";
    string com_str = "123abcABC,.123abcABC,.";
    string *uncompressed=&un_str;
    string *compressed=&com_str;

    FastGzipString(*uncompressed, compressed);

        std::cout<<*compressed<<std::endl;
    FastGunzipString(*compressed,uncompressed);

    std::cout<<*uncompressed<<std::endl;
    return 0;

}

