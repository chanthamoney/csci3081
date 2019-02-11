#include "gtest/gtest.h"
#include <iostream>
#include <math.h>
#include <ctime>
#include "date.h"
/*
	Test
*/
/*
TESTING FEEDBACK
*/
class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  new_year = Date(2019, 1, 1);
  new_year18 = Date(2018, 1, 1);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date new_year;
  Date new_year18;
};

TEST_F(DateTest, ConstructorDateTest) {
  Date today;                       // current date
  Date WeekEpoch(604800);                //adding a week epoch
  Date NegEpoch(-604800);               //Negative week Epoch
  Date newYear(2019, 1, 1);

  const int MAXLEN = 80;
  char s[MAXLEN];
  time_t t = time(0);
  strftime(s, MAXLEN, "%Y-%m-%d\n", localtime(&t));
  //std::cout << s << '\n';
  std::string expected_out_1 = s; //current date
  std::string expected_out_2 = "1970-01-08\n"; //epoch OFFSET by 70 years
  std::string expected_out_3 = "1969-12-25\n";
  std::string expected_out_4 = "2019-01-01\n";

  testing::internal::CaptureStdout();
  today.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  WeekEpoch.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  NegEpoch.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  newYear.PrintDate(true);
  std::string output4 = testing::internal::GetCapturedStdout();


  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);

}

TEST_F(DateTest, OperatorPlusTest){
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  Date January(2019, 1, 31);
  Date February(2019, 2, 28);
  Date March(2019, 3, 31);
  Date April(2019, 4, 30);
  Date May(2019, 5, 31);
  Date June(2019, 6, 30);
  Date July(2019, 7, 31);
  Date August(2019, 8, 31);
  Date September(2019, 9, 30);
  Date October(2019, 10, 31);
  Date November(2019, 11, 30);
  Date December(2019, 12, 31);

  EXPECT_EQ((ind_day+10).GetUsDate(), "07-14-1776");
  EXPECT_EQ((ind_day+0).GetUsDate(), "07-04-1776");
  EXPECT_EQ((ind_day+(-2)).GetUsDate(), "07-02-1776");
  EXPECT_EQ((ind_day+365).GetUsDate(), "07-04-1777");
  EXPECT_EQ((ind_day+(365*4)).GetUsDate(), "07-03-1780");

  EXPECT_EQ((January+1).GetUsDate(), "02-01-2019");
  EXPECT_EQ((February+1).GetUsDate(), "03-01-2019");
  EXPECT_EQ((March+1).GetUsDate(), "04-01-2019");
  EXPECT_EQ((April+1).GetUsDate(), "05-01-2019");
  EXPECT_EQ((May+1).GetUsDate(), "06-01-2019");
  EXPECT_EQ((June+1).GetUsDate(), "07-01-2019");
  EXPECT_EQ((July+1).GetUsDate(), "08-01-2019");
  EXPECT_EQ((August+1).GetUsDate(), "09-01-2019");
  EXPECT_EQ((September+1).GetUsDate(), "10-01-2019");
  EXPECT_EQ((October+1).GetUsDate(), "11-01-2019");
  EXPECT_EQ((November+1).GetUsDate(), "12-01-2019");
  EXPECT_EQ((December+1).GetUsDate(), "01-01-2020");
}

TEST_F(DateTest, OperatorMinusTest){
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  Date January(2019, 1, 1);
  Date February(2019, 2, 1);
  Date March(2019, 3, 1);
  Date April(2019, 4, 1);
  Date May(2019, 5, 1);
  Date June(2019, 6, 1);
  Date July(2019, 7, 1);
  Date August(2019, 8, 1);
  Date September(2019, 9, 1);
  Date October(2019, 10, 1);
  Date November(2019, 11, 1);
  Date December(2019, 12, 1);

  EXPECT_EQ((ind_day-2).GetUsDate(), "07-02-1776");
  EXPECT_EQ((ind_day-0).GetUsDate(), "07-04-1776");
  EXPECT_EQ((ind_day-(-2)).GetUsDate(), "07-06-1776");
  EXPECT_EQ((ind_day-365).GetUsDate(), "07-05-1775");
  EXPECT_EQ((ind_day-(365*4)).GetUsDate(), "07-05-1772");

  EXPECT_EQ((January-1).GetUsDate(), "12-31-2018");
  EXPECT_EQ((February-1).GetUsDate(), "01-31-2019");
  EXPECT_EQ((March-1).GetUsDate(), "02-28-2019");
  EXPECT_EQ((April-1).GetUsDate(), "03-31-2019");
  EXPECT_EQ((May-1).GetUsDate(), "04-30-2019");
  EXPECT_EQ((June-1).GetUsDate(), "05-31-2019");
  EXPECT_EQ((July-1).GetUsDate(), "06-30-2019");
  EXPECT_EQ((August-1).GetUsDate(), "07-31-2019");
  EXPECT_EQ((September-1).GetUsDate(), "08-31-2019");
  EXPECT_EQ((October-1).GetUsDate(), "09-30-2019");
  EXPECT_EQ((November-1).GetUsDate(), "10-31-2019");
  EXPECT_EQ((December-1).GetUsDate(), "11-30-2019");
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  Date new_year2016(2016, 1, 1);
  Date March2016(2016, 3, 1);

  Date Birthday(1998, 7, 17);
  Date DayAfterBirthday(1998, 7, 18);

  Date JanuaryFirst(2019, 1, 1);
  Date FebruaryFirst(2019, 2, 1);
  Date MarchFirst(2019, 3, 1);
  Date AprilFirst(2019, 4, 1);
  Date MayFirst(2019, 5, 1);
  Date JuneFirst(2019, 6, 1);
  Date JulyFirst(2019, 7, 1);
  Date AugustFirst(2019, 8, 1);
  Date SeptemberFirst(2019, 9, 1);
  Date OctoberFirst(2019, 10, 1);
  Date NovemberFirst(2019, 11, 1);
  Date DecemberFirst(2019, 12, 1);

  Date JanuaryLast(2019, 1, 31);
  Date FebruaryLast(2019, 2, 28);
  Date MarchLast(2019, 3, 31);
  Date AprilLast(2019, 4, 30);
  Date MayLast(2019, 5, 31);
  Date JuneLast(2019, 6, 30);
  Date JulyLast(2019, 7, 31);
  Date AugustLast(2019, 8, 31);
  Date SeptemberLast(2019, 9, 30);
  Date OctoberLast(2019, 10, 31);
  Date NovemberLast(2019, 11, 30);
  Date DecemberLast(2019, 12, 31);

  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(first_day.DaysBetween(first_day), 0);
  EXPECT_EQ(new_year.DaysBetween(new_year18), 365);
  EXPECT_EQ(new_year18.DaysBetween(new_year), 365);
  EXPECT_EQ(Birthday.DaysBetween(DayAfterBirthday), 1);
  EXPECT_EQ(new_year2016.DaysBetween(March2016), 60);
  EXPECT_EQ(JanuaryFirst.DaysBetween(JanuaryLast), 30);
  EXPECT_EQ(FebruaryFirst.DaysBetween(FebruaryLast), 27);
  EXPECT_EQ(MarchFirst.DaysBetween(MarchLast), 30);
  EXPECT_EQ(AprilFirst.DaysBetween(AprilLast), 29);
  EXPECT_EQ(MayFirst.DaysBetween(MayLast), 30);
  EXPECT_EQ(JuneFirst.DaysBetween(JuneLast), 29);
  EXPECT_EQ(JulyFirst.DaysBetween(JulyLast), 30);
  EXPECT_EQ(AugustFirst.DaysBetween(AugustLast), 30);
  EXPECT_EQ(SeptemberFirst.DaysBetween(SeptemberLast), 29);
  EXPECT_EQ(OctoberFirst.DaysBetween(OctoberLast), 30);
  EXPECT_EQ(NovemberFirst.DaysBetween(NovemberLast), 29);
  EXPECT_EQ(DecemberFirst.DaysBetween(DecemberLast), 30);

}


TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween


  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();


  EXPECT_EQ(output1, expected_out_1) << "New line in YYYY-MM-DD";
  EXPECT_EQ(output2, expected_out_2) << "New line in YYYY-MM-DD";
  EXPECT_EQ(output3, expected_out_3) << "New line in YYYY-MM-DD";
  EXPECT_EQ(output1, (y2k.GetDate()+"\n")) << "New line in YYYY-MM-DD with GetDate";
  EXPECT_EQ(output2, (ind_day.GetDate()+"\n")) << "New line in YYYY-MM-DD with GetDate";
  EXPECT_EQ(output3, (best_holiday.GetDate()+"\n")) << "New line in YYYY-MM-DD with GetDate";

}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1) << "No New line in YYYY-MM-DD";
  EXPECT_EQ(output2, expected_out_2) << "No New line in YYYY-MM-DD";
  EXPECT_EQ(output3, expected_out_3) << "No New line in YYYY-MM-DD";
  EXPECT_EQ(output1, y2k.GetDate()) << "No New line in YYYY-MM-DD with GetDate";
  EXPECT_EQ(output2, ind_day.GetDate()) << "No New line in YYYY-MM-DD with GetDate";
  EXPECT_EQ(output3, best_holiday.GetDate()) << "No New line in YYYY-MM-DD with GetDate";
}


TEST_F(DateTest, PrintUSDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween


  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();


  EXPECT_EQ(output1, expected_out_1) << "New line in MM-DD-YYYY";
  EXPECT_EQ(output2, expected_out_2) << "New line in MM-DD-YYYY";
  EXPECT_EQ(output3, expected_out_3) << "New line in MM-DD-YYYY";
  EXPECT_EQ(output1, (y2k.GetUsDate()+"\n")) << "New line in MM-DD-YYYY with GetUsDate";
  EXPECT_EQ(output2, (ind_day.GetUsDate()+"\n")) << "New line in MM-DD-YYYY with GetUsDate";
  EXPECT_EQ(output3, (best_holiday.GetUsDate()+"\n")) << "New line in MM-DD-YYYY with GetUsDate";

}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1) << "No New line in MM-DD-YYYY";
  EXPECT_EQ(output2, expected_out_2) << "No New line in MM-DD-YYYY";
  EXPECT_EQ(output3, expected_out_3) << "No New line in MM-DD-YYYY";
  EXPECT_EQ(output1, y2k.GetUsDate()) << "No New line in MM-DD-YYYY with GetUsDate";
  EXPECT_EQ(output2, ind_day.GetUsDate()) << "No New line in MM-DD-YYYY with GetUsDate";
  EXPECT_EQ(output3, best_holiday.GetUsDate()) << "No New line in MM-DD-YYYY with GetUsDate";
}


/*
TODO: MM-DD-YYYY and then ask jake how to do private methods testing :()
*/

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
