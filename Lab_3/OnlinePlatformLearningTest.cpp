#include "pch.h"
#include "CppUnitTest.h"
#include "../OnlineLearningPlatform_Lab3/HumanResources.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OnlinePlatformLearningTest
{
	TEST_CLASS(OnlinePlatformLearningTest)
	{
	public:
		TEST_METHOD(CreateAdditionalMaterialTest)
		{
			string link = "LINK", name = "Wikipedia";
			AdditionalMaterial addMaterial(name);
			addMaterial.setLink(link);
			Assert::AreEqual(addMaterial.getNameOfMaterial(), name);
			Assert::AreEqual(addMaterial.getLink(), link);
			Assert::AreEqual(addMaterial.getIsExamined(), false);
		}
		TEST_METHOD(CreateTextMaterialTest)
		{
			string text = "Text of lesson.", name = "NAME OF LESSON";
			TextMaterial textMaterial(name);
			textMaterial.setTextMaterial(text);
			Assert::AreEqual(textMaterial.getNameOfMaterial(), name);
			Assert::AreEqual(textMaterial.getTextMeterial(), text);
			Assert::AreEqual(textMaterial.getIsExamined(), false);
		}
		TEST_METHOD(CreateVideoMaterialTest)
		{
			string link = "LINK", name = "Youtube";
			VideoMaterial videoMaterial(name);
			videoMaterial.setLink(link);
			Assert::AreEqual(videoMaterial.getNameOfMaterial(), name);
			Assert::AreEqual(videoMaterial.getLink(), link);
			Assert::AreEqual(videoMaterial.getIsExamined(), false);
		}

		TEST_METHOD(SetAssigmentTest) 
		{
			IndividTask task;
			string assigment = "ASSIGMENT";
			task.setAssigment(assigment);
			Assert::AreEqual(task.getAssigment(), assigment);
		}
		TEST_METHOD(SetCompliteTest)
		{
			IndividTask task;
			task.setComplite();
			Assert::AreEqual(task.getComplite(), true);
		}
		TEST_METHOD(SetAnswerTest)
		{
			IndividTask task;
			string answer = "STUDENT ANSWER";
			task.setAnswer(answer);
			Assert::AreEqual(task.getAnswer(), answer);
		}
		TEST_METHOD(SetMarkTest)
		{
			IndividTask task;
			int mark = 9;
			task.setMark(mark);
			Assert::AreEqual(task.getMark(), mark);
		}
		TEST_METHOD(SetCommentTest)
		{
			IndividTask task;
			string comment = "COMMENT OF INSTRUCTOR";
			task.setComments(comment);
			Assert::AreEqual(task.getComment(), comment);
		}

		TEST_METHOD(SetPersonalAccountNumberTest)
		{
			PersonalAccountNumber account;
			string number = "";
			account.setNumberOfPersonalAccount();
			Assert::AreNotEqual(account.getAccountNumber(), number);
		}
		TEST_METHOD(SetPersonalAccountNumberCashTest)
		{
			PersonalAccountNumber account;
			int cash1 = 0, cash2 = 10, cash3 = 20;
			Assert::AreEqual(account.getCash(), cash1);
			account.setCash(cash2);
			Assert::AreEqual(account.getCash(), cash2);
			account.setCash(cash2);
			Assert::AreEqual(account.getCash(), cash3);
		}

		TEST_METHOD(SetStudentCertificateTest) 
		{
			Student bob("Bob", "Minsk");
			Assert::AreEqual(bob.getCertificate(), false);
			bob.setCertificate();
			Assert::AreEqual(bob.getCertificate(), true);
		}
		TEST_METHOD(SetStudentRegistrationTest)
		{
			Student bob("Bob", "Minsk");
			string account = "";
			bob.registration();
			Assert::AreNotEqual(bob.getAccount().getAccountNumber(), account);
		}
		TEST_METHOD(SetStudentPaymentTest)
		{
			Student bob("Bob", "Minsk");
			int payment = 100;
			bob.payFor(payment);
			Assert::AreEqual(bob.getAccount().getCash(), payment);
		}

		TEST_METHOD(SetLessonNameandTopicTest) 
		{
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			Lesson newLesson(name, topic);
			Assert::AreEqual(newLesson.getNameOfLesson(), name);
			Assert::AreEqual(newLesson.getLessonTopic(), topic);
		}
		TEST_METHOD(SetLessonAccessTest) 
		{
			Lesson newLesson;
			Assert::AreEqual(newLesson.getAccessToLesson(), false);
			newLesson.setAccessToLesson();
			Assert::AreEqual(newLesson.getAccessToLesson(), true);
		}
		TEST_METHOD(SetLessonTextMaterialTest) 
		{
			string text = "TEXT OF LESSON";
			Lesson newLesson;
			newLesson.setTextOfLesson(text);
			Assert::AreEqual(newLesson.getTextMaterial().getTextMeterial(), text);
		}
		TEST_METHOD(SetLessonVideoMaterialTest)
		{
			string link = "LINK OF LESSON";
			Lesson newLesson;
			newLesson.setListOfVideo(link);
			Assert::AreEqual(newLesson.getVideoMaterial().getLink(), link);
		}
		TEST_METHOD(SetLessonAddMaterialTest)
		{
			string link = "LINK OF ADDITIONAL INFORMATION";
			Lesson newLesson;
			newLesson.setAddMaterial(link);
			Assert::AreEqual(newLesson.getAddMaterial().getLink(), link);
		}
		TEST_METHOD(SetLessonHomeworkTest)
		{
			string assigment = "ASSIGMENT OF LESSON";
			Lesson newLesson;
			newLesson.setHomework(assigment);
			Assert::AreEqual(newLesson.getHomework().getAssigment(), assigment);
		}

		TEST_METHOD(SetCourceNameTest) 
		{
			string name = "COURCE NAME";
			Cource newCource;
			newCource.setNameOfCource(name);
			Assert::AreEqual(newCource.getNameOfCource(), name);
		}
		TEST_METHOD(SetCourceTopicTest)
		{
			string topic = "COURCE TOPIC";
			Cource newCource;
			newCource.setTopicOfCource(topic);
			Assert::AreEqual(newCource.getCourceTopic(), topic);
		}
		TEST_METHOD(SetCourceLessonTest)
		{
			Cource newCource("COURCE NAME", "COURCE TOPIC");
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			Lesson newLesson(name, topic);
			newCource.setListOfLessons(newLesson);
			Assert::AreEqual(newCource.getLesson(0).getNameOfLesson(), name);
			Assert::AreEqual(newCource.getLesson(0).getLessonTopic(), topic);
		}
		TEST_METHOD(SetCourceLearningLessonTest)
		{
			Cource newCource("COURCE NAME", "COURCE TOPIC");
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			Lesson newLesson(name, topic);
			newCource.setListOfLessons(newLesson);
			newCource.setListOfLearnedLessons(newLesson);
			int numberOfLesson = 1, numberOfLearningLesson = 1;
			Assert::AreEqual(newCource.CalculationOfNumberOfAllLesson(), numberOfLesson);
			Assert::AreEqual(newCource.CalculationOfNumberOfLearnedLesson(), numberOfLearningLesson);
		}
		TEST_METHOD(SetCourceResetProgressTest)
		{
			Cource newCource("COURCE NAME", "COURCE TOPIC");
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			Lesson newLesson(name, topic);
			newCource.setListOfLessons(newLesson);
			newCource.setListOfLearnedLessons(newLesson);
			int numberOfLearningLesson = 1;
			Assert::AreEqual(newCource.CalculationOfNumberOfLearnedLesson(), numberOfLearningLesson);
			newCource.resetProgress();
			numberOfLearningLesson = 0;
			Assert::AreEqual(newCource.CalculationOfNumberOfLearnedLesson(), numberOfLearningLesson);
		}
		TEST_METHOD(SetCourceSearchingLessonTest)
		{
			Cource newCource("COURCE NAME", "COURCE TOPIC");
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			Lesson newLesson(name, topic);
			string name2 = "SECOND NAME OF LESSON", topic2 = "SECOND TOPIC OF LESSON";
			Lesson newLesson2(name2, topic2);
			newCource.setListOfLessons(newLesson);
			newCource.setListOfLessons(newLesson2);
			int numberOfLesson = 0, numberOfLesson2 = 1;
			int numberSeerch = newCource.searchOfLesson(name);
			int numberSeerch2 = newCource.searchOfLesson(name2);
			Assert::AreEqual(numberSeerch, numberOfLesson);
			Assert::AreEqual(numberSeerch2, numberOfLesson2);
		}
		TEST_METHOD(SetCourceInstructorTest)
		{
			string name = "INSTRUCTOR NAME";
			Cource newCource;
			newCource.setInstructor(name);
			Assert::AreEqual(newCource.getInctructorNameOfCource(), name);
		}

		TEST_METHOD(CreateNewLessonTest) 
		{
			Instructor teacher("Name", "Info", "Programming", 6);
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			teacher.createLesson(name, topic);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getNameOfLesson(), name);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getLessonTopic(), topic);
		}
		TEST_METHOD(AttachTextMaterialOfLessonTest) 
		{
			Instructor teacher;
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON", text = "TEXT";
			teacher.createLesson(name, topic);
			teacher.attachTextMaterial(name, text);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getTextMaterial().getTextMeterial(), text);
		}
		TEST_METHOD(AttachVideoMaterialOfLessonTest)
		{
			Instructor teacher;
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON", link = "LINK";
			teacher.createLesson(name, topic);
			teacher.attachVideoMaterial(name, link);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getVideoMaterial().getLink(), link);
		}
		TEST_METHOD(AttachAdditionalMaterialOfLessonTest)
		{
			Instructor teacher;
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON", link = "LINK";
			teacher.createLesson(name, topic);
			teacher.attachAdditionalMaterial(name, link);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getAddMaterial().getLink(), link);
		}
		TEST_METHOD(OpenAccessToLessonTest)
		{
			Instructor teacher;
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON";
			teacher.createLesson(name, topic);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getAccessToLesson(), false);
			teacher.openAccessToLesson(name);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getAccessToLesson(), true);
		}
		TEST_METHOD(GiveHomeworkTest)
		{
			Instructor teacher;
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON", assigment = "ASSIGMENT";
			teacher.createLesson(name, topic);
			teacher.giveHomework(name, assigment);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getHomework().getAssigment(), assigment);
		}
		TEST_METHOD(CheckHomeworkLessonTest)
		{
			Instructor teacher;
			string name = "NAME OF LESSON", topic = "TOPIC OF LESSON", comment = "COMMENT";
			int mark = 9;
			teacher.createLesson(name, topic);
			teacher.checkHomework(name, mark, comment);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getHomework().getMark(), mark);
			Assert::AreEqual(teacher.getTaughtCource().getLesson(0).getHomework().getComment(), comment);
		}
	};
}
