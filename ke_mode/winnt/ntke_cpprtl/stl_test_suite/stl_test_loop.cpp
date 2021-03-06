/////////////////////////////////////////////////////////////////////////////
////    copyright (c) 2012-2017 project_ntke_cpprtl
////    mailto:kt133a@seznam.cz
////    license: the MIT license
/////////////////////////////////////////////////////////////////////////////


#include "stl_test_loop.h"
#include "tests.h"


namespace
{
  enum
  {
    IDX_FACTOR = 10000000
  };


  using namespace cpprtl::test::stl;


  test_ft* const test_table_thread_safe[] =
  {
    0

    , &test_stl01
    , &test_stl02
    , &test_stl03
    , &test_stl04
    , &test_stl05
    , &test_stl06
  //  , &test_stl07
  //  , &test_stl08
  //  , &test_stl09
  //  , &test_stl10
  //  , &test_stl11
  //  , &test_stl12
  //  , &test_stl13
  //  , &test_stl14
  //  , &test_stl15
  //  , &test_stl16
  //  , &test_stl17
  //  , &test_stl18
  //  , &test_stl19

    , 0
  };


  unsigned test_num_thread_safe()
  {
    return sizeof(test_table_thread_safe) / sizeof(test_table_thread_safe[0]);
  }

}  // namespace


namespace cpprtl  { namespace test  { namespace stl
{

  int run()
  {
    unsigned idx = 0;
    int res = 0;
    for ( ; idx < test_num_thread_safe() ; ++idx )
    {
      if ( test_table_thread_safe[idx] )
      {
        if ( 0 != (res = test_table_thread_safe[idx]()) )
        {
          break;
        }
      }
    }
    return res ? idx * IDX_FACTOR + res : 0;
  }

}  }  }

