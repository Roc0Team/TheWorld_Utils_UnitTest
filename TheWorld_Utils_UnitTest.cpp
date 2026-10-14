#include "pch.h"
#include "CppUnitTest.h"
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheWorldUtilsUnitTest
{
	TEST_CLASS(TheWorldUtilsUnitTests)
	{
		constexpr static const char* nome_Int32_1 = "Nome_Int32_1";
		constexpr static const char* nome_Int32_2 = "Nome_Int32_2";
		constexpr static const char* nome_Int32_3 = "Nome_Int32_3";
		constexpr static const char* nome_Int32_4 = "Nome_Int32_4";
		constexpr static const char* nome_Int32_5 = "Nome_Int32_5";
		constexpr static const char* nome_Int32_6 = "Nome_Int32_6";
		constexpr static const char* nome_Int32_7 = "Nome_Int32_7";
		constexpr static const char* nome_Int32_8 = "Nome_Int32_8";
		constexpr static const char* nome_Int64_1 = "Nome_Int64_1";
		constexpr static const char* nome_Int64_2 = "Nome_Int64_2";
		constexpr static const char* nome_Size_1 = "Nome_Size_1";
		constexpr static const char* nome_Size_2 = "Nome_Size_2";
		constexpr static const char* nome_Float_1 = "Nome_Float_1";
		constexpr static const char* nome_Float_2 = "Nome_Float_2";
		constexpr static const char* nome_Double_1 = "Nome_Double_1";
		constexpr static const char* nome_Double_2 = "Nome_Double_2";
		constexpr static const char* nome_String_1 = "Nome_String_1";
		constexpr static const char* nome_String_2 = "Nome_String_2";
		constexpr static const char* nome_String_3 = "Nome_String_3";
		constexpr static const char* nome_Buffer_1 = "Nome_Buffer_1";
		constexpr static const char* nome_Buffer_2 = "Nome_Buffer_2";
		constexpr static const char* nome_Buffer_3 = "Nome_Buffer_3";
		constexpr static const char* nome_dummy_1 = "Nome_Dummy_1";
		constexpr static const char* nome_dummy_2 = "Nome_Dummy_2";

	public:
		
		TEST_METHOD(NamedDataBufferTest)
		{
			TheWorld_Utils::NamedDataBuffer namedDataBuffer;

			int32_t int32_out = 0;
			int64_t int64_out = 0;
			size_t size_out = 0;
			float float_out = 0;
			double double_out = 0;
			TheWorld_Utils::MemoryBuffer buffer_out;
			std::string string_out;

			bool b;
			int32_t _flags = 0;	// not used at, but required by get... methods

			// simple types on the root level
			int32_t int32_1 = 123;
			namedDataBuffer.add<int32_t>(int32_1, nome_Int32_1);
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_1 == int32_out);

			namedDataBuffer.remove(nome_Int32_1);
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_1, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add<int32_t>(int32_1, nome_Int32_1);
			namedDataBuffer.get<int32_t>(int32_out, nome_Int32_1, _flags);
			Assert::IsTrue(int32_1 == int32_out);

			int32_t int32_2 = 456;
			namedDataBuffer.add<int32_t>(int32_2, nome_Int32_2);
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_2 == int32_out);

			int64_t int64_1 = 789;
			namedDataBuffer.add<int64_t>(int64_1, nome_Int64_1);
			b = namedDataBuffer.get<int64_t>(int64_out, nome_Int64_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int64_1 == int64_out);

			namedDataBuffer.remove(nome_Int64_1);
			b = namedDataBuffer.get<int64_t>(int64_out, nome_Int64_1, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add<int64_t>(int64_1, nome_Int64_1);
			b = namedDataBuffer.get<int64_t>(int64_out, nome_Int64_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int64_1 == int64_out);

			int64_t int64_2 = 712;
			namedDataBuffer.add<int64_t>(int64_2, nome_Int64_2);
			b = namedDataBuffer.get<int64_t>(int64_out, nome_Int64_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int64_2 == int64_out);

			size_t size_1 = 789;
			namedDataBuffer.add<size_t>(size_1, nome_Size_1);
			b = namedDataBuffer.get<size_t>(size_out, nome_Size_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_1 == size_out);

			namedDataBuffer.remove(nome_Size_1);
			b = namedDataBuffer.get<size_t>(size_out, nome_Size_1, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add<size_t>(size_1, nome_Size_1);
			b = namedDataBuffer.get<size_t>(size_out, nome_Size_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_1 == size_out);

			size_t size_2 = 722;
			namedDataBuffer.add<size_t>(size_2, nome_Size_2);
			b = namedDataBuffer.get<size_t>(size_out, nome_Size_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_2 == size_out);
			
			float float_1 = 789.33f;
			namedDataBuffer.add<float>(float_1, nome_Float_1);
			b = namedDataBuffer.get<float>(float_out, nome_Float_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(float_1 == float_out);

			namedDataBuffer.remove(nome_Float_1);
			b = namedDataBuffer.get<float>(float_out, nome_Float_1, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add<float>(float_1, nome_Float_1);
			b = namedDataBuffer.get<float>(float_out, nome_Float_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(float_1 == float_out);

			float float_2 = 722.11f;
			namedDataBuffer.add<float>(float_2, nome_Float_2);
			b = namedDataBuffer.get<float>(float_out, nome_Float_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(float_2 == float_out);

			double double_1 = 789.33;
			namedDataBuffer.add<double>(double_1, nome_Double_1);
			b = namedDataBuffer.get<double>(double_out, nome_Double_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(double_1 == double_out);

			double double_2 = 722.11;
			namedDataBuffer.add<double>(double_2, nome_Double_2);
			b = namedDataBuffer.get<double>(double_out, nome_Double_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(double_2 == double_out);

			namedDataBuffer.remove(nome_Double_2);
			b = namedDataBuffer.get<double>(double_out, nome_Double_2, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add<double>(double_2, nome_Double_2);
			b = namedDataBuffer.get<double>(double_out, nome_Double_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(double_2 == double_out);

			// string
			std::string string_1 = "Stringa 1";
			namedDataBuffer.add(string_1, nome_String_1);
			b = namedDataBuffer.get(string_out, nome_String_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_1 == string_out);

			namedDataBuffer.remove(nome_String_1);
			b = namedDataBuffer.get(string_out, nome_String_1, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add(string_1, nome_String_1);
			b = namedDataBuffer.get(string_out, nome_String_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_1 == string_out);

			std::string string_2 = "Stringa 2";
			namedDataBuffer.add(string_2, nome_String_2);
			b = namedDataBuffer.get(string_out, nome_String_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_2 == string_out);

			std::string string_3 = "Stringa 3";
			namedDataBuffer.add(string_3, nome_String_3);
			b = namedDataBuffer.get(string_out, nome_String_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_3 == string_out);

			int32_t int32_3 = 777;
			namedDataBuffer.add<int32_t>(int32_3, nome_Int32_3);
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_3 == int32_out);

			// buffer
			TheWorld_Utils::MemoryBuffer buffer_1 = namedDataBuffer.getInternalBuffer();
			namedDataBuffer.add(buffer_1, nome_Buffer_1);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_1 == buffer_out);

			namedDataBuffer.remove(nome_Buffer_1);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_1, _flags);
			Assert::IsFalse(b);

			namedDataBuffer.add(buffer_1, nome_Buffer_1);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_1 == buffer_out);

			TheWorld_Utils::MemoryBuffer buffer_2;
			namedDataBuffer.add(buffer_2, nome_Buffer_2);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_2 == buffer_out);

			// Replace string of various sizes
			string_3 = "Stringa 3 old";
			namedDataBuffer.add(string_3, nome_String_3);
			b = namedDataBuffer.get(string_out, nome_String_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_3 == string_out);

			int32_t int32_8 = 888;
			namedDataBuffer.add<int32_t>(int32_8, nome_Int32_8);
			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_8, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_8 == int32_out);

			string_3 = "Stringa 3 new";		// same length as previous string, should be replaced in place
			namedDataBuffer.add(string_3, nome_String_3);
			b = namedDataBuffer.get(string_out, nome_String_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_3 == string_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_8, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_8 == int32_out);

			string_3 = "Stringa 3 n";			// new string shorter than old one
			namedDataBuffer.add(string_3, nome_String_3);
			b = namedDataBuffer.get(string_out, nome_String_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_3 == string_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_8, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_8 == int32_out);

			string_3 = "Stringa 3 newnew";			// new string longer than old one
			namedDataBuffer.add(string_3, nome_String_3);
			b = namedDataBuffer.get(string_out, nome_String_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(string_3 == string_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_8, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_8 == int32_out);

			// Replace buffers of various sizes
			TheWorld_Utils::MemoryBuffer buffer_3("Buffer 3 old");
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_3 == buffer_out);

			int32_t int32_7 = 777;
			namedDataBuffer.add<int32_t>(int32_7, nome_Int32_7);
			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_7, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_7 == int32_out);

			size_t size_3(111);
			namedDataBuffer.add(size_3, nome_dummy_2);
			b = namedDataBuffer.get(size_out, nome_dummy_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_3 == size_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_7, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_7 == int32_out);

			buffer_3 = "Buffer 3 new";		// same length as previous buffer, should be replaced in place
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_3 == buffer_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_7, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_7 == int32_out);

			buffer_3 = "Buffer 3 n";			// new buffer shorter than old one
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_3 == buffer_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_7, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_7 == int32_out);

			buffer_3 = "Buffer 3 newnew";			// new buffer longer than old one
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_3 == buffer_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_7, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_7 == int32_out);

			b = namedDataBuffer.get(size_out, nome_dummy_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_3 == size_out);

			// Replace other data types of various sizes
			size_3 = 222;
			namedDataBuffer.add(size_3, nome_dummy_2);
			b = namedDataBuffer.get(size_out, nome_dummy_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_3 == size_out);

			int32_t int32_6 = 666;
			namedDataBuffer.add<int32_t>(int32_6, nome_Int32_6);
			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_6, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_6 == int32_out);

			int64_t int64_3 = 333;			// same length as previous data, should be replaced in place
			namedDataBuffer.add(int64_3, nome_dummy_2);
			b = namedDataBuffer.get(int64_out, nome_dummy_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int64_3 == int64_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_6, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_6 == int32_out);

			int32_3 = 444;			// new buffer shorter than old one
			namedDataBuffer.add(int32_3, nome_dummy_2);
			b = namedDataBuffer.get(int32_out, nome_dummy_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_3 == int32_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_6, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_6 == int32_out);

			size_3 = 555;
			namedDataBuffer.add(size_3, nome_dummy_2);
			b = namedDataBuffer.get(size_out, nome_dummy_2, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(size_3 == size_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_6, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_6 == int32_out);

			buffer_3 = "Buffer 3 n";			// new buffer shorter than old one
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			b =	namedDataBuffer.get(buffer_out, nome_Buffer_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_3 == buffer_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_6, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_6 == int32_out);

			buffer_3 = "Buffer 3 newnew";			// new buffer longer than old one
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(buffer_3 == buffer_out);

			int32_out = 0;
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_6, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_6 == int32_out);

			// attach buffer
			b = namedDataBuffer.get<int32_t>(int32_1, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			b = namedDataBuffer.get(buffer_out, nome_Buffer_1, _flags);
			Assert::IsTrue(b);
			TheWorld_Utils::NamedDataBuffer namedDataBuffer1(buffer_out);
			b = namedDataBuffer1.get<int32_t>(int32_out, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_1 == int32_out);

			b = namedDataBuffer.get<int32_t>(int32_1, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			TheWorld_Utils::NamedDataBuffer namedDataBuffer2(namedDataBuffer);
			b = namedDataBuffer2.get<int32_t>(int32_out, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_1 == int32_out);
			//Assert::IsTrue(namedDataBuffer2 == namedDataBuffer);

			// serialize/deserialize
			int32_3 = 777;
			namedDataBuffer.add<int32_t>(int32_3, nome_Int32_3);
			TheWorld_Utils::MemoryBuffer serializationBuffer;
			namedDataBuffer.serialize(serializationBuffer);
			TheWorld_Utils::NamedDataBuffer deserializedNamedDataBuffer;
			deserializedNamedDataBuffer.deserialize(serializationBuffer);
			b = deserializedNamedDataBuffer.get<int32_t>(int32_out, nome_Int32_3, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_3 == int32_out);

			// try to add without replace 
			int32_t oldValue;
			b = namedDataBuffer.get<int32_t>(oldValue, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			int32_1 = 888;
			namedDataBuffer.add<int32_t>(int32_1, nome_Int32_1, false);
			b = namedDataBuffer.get<int32_t>(int32_out, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(oldValue == int32_out);
			
			// add with replace 
			int32_1 = 888;
			namedDataBuffer.add(int32_1, nome_Int32_1);
			b = namedDataBuffer.get(int32_out, nome_Int32_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_1 == int32_out);

			std::string dummy_1_str = "dummy_1_str";
			namedDataBuffer.add(dummy_1_str, nome_dummy_1);
			b = namedDataBuffer.get(string_out, nome_dummy_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(dummy_1_str == string_out);
			int32_t dummy_1_int32 = 370;
			namedDataBuffer.add<int32_t>(dummy_1_int32, nome_dummy_1);
			b = namedDataBuffer.get<int32_t>(int32_out, nome_dummy_1, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(dummy_1_int32 == int32_out);

			int32_t int32_4 = 888;
			namedDataBuffer.add<int32_t>(int32_4, nome_Int32_4);
			b = namedDataBuffer.get(int32_out, nome_Int32_4, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_4 == int32_out);

			bool exists = namedDataBuffer.exists<int32_t>(nome_Int32_4);
			Assert::IsTrue(exists);	
			exists = namedDataBuffer.exists<int32_t>(nome_Int32_5);
			Assert::IsFalse(exists);

			std::vector<std::string> names;
			namedDataBuffer.getNames(names);

			// Groups
			int32_1 = 888;
			std::string name = std::string("Group_1.") + nome_Int32_4;
			namedDataBuffer.add<int32_t>(int32_4, name);
			b = namedDataBuffer.get(int32_out, name, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_4 == int32_out);
			namedDataBuffer.getNames(names);

			name = std::string("Group_1.") + nome_Int32_2;
			namedDataBuffer.add<int32_t>(int32_2, name);
			b = namedDataBuffer.get(int32_out, name, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_2 == int32_out);
			namedDataBuffer.getNames(names);

			name = std::string("Group_1.Group_1_1.") + nome_Int32_4;
			namedDataBuffer.add<int32_t>(int32_4, name);
			b = namedDataBuffer.get(int32_out, name, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_4 == int32_out);
			namedDataBuffer.getNames(names);

			name = std::string("Group_1.Group_1_1.") + nome_Int32_2;
			namedDataBuffer.add<int32_t>(int32_2, name);
			b = namedDataBuffer.get(int32_out, name, _flags);
			Assert::IsTrue(b);
			Assert::IsTrue(int32_2 == int32_out);
			namedDataBuffer.getNames(names);

			namedDataBuffer1.add<int32_t>(int32_3, nome_Int32_3);
			namedDataBuffer1.add<size_t>(size_1, nome_Size_1);
			std::string s = "Stringa 1";
			namedDataBuffer1.add(s, nome_String_1);
			namedDataBuffer.addGroup(namedDataBuffer1, "Group_2");
			namedDataBuffer.getNames(names);

			TheWorld_Utils::NamedDataBuffer namedDataBuffer3;
			b = namedDataBuffer.getGroup(namedDataBuffer3, "Group_1", _flags);
			Assert::IsTrue(b);
			namedDataBuffer3.getNames(names);
			b = namedDataBuffer.getGroup(namedDataBuffer3, "Group_2", _flags);
			Assert::IsTrue(b);
			namedDataBuffer3.getNames(names);

			// Variant
			int32_1 = 123;
			namedDataBuffer.add<int32_t>(int32_1, nome_Int32_1);
			TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant_1 = namedDataBuffer.getVariant<int32_t>(nome_Int32_1, _flags);
			Assert::IsTrue(not TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_1));
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<int32_t>(variant_1));
			Assert::IsTrue(std::get<int32_t>(variant_1) == int32_1);
			int32_out = std::get<int32_t>(namedDataBuffer[nome_Int32_1]);
			Assert::IsTrue(int32_out == int32_1);

			string_1 = "Stringa 1";
			namedDataBuffer.add(string_1, nome_String_1);
			TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant_2 = namedDataBuffer.getVariant<std::string>(nome_String_1, _flags);
			Assert::IsTrue(not TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_2));
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<std::string>(variant_2));
			Assert::IsTrue(std::get<std::string>(variant_2) == string_1);
			string_out = std::get<std::string>(namedDataBuffer[nome_String_1]);
			Assert::IsTrue(string_out == string_1);

			TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant_3 = namedDataBuffer.getVariant<TheWorld_Utils::MemoryBuffer>(nome_Buffer_1, _flags);
			Assert::IsTrue(not TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_3));
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<TheWorld_Utils::MemoryBuffer>(variant_3));
			TheWorld_Utils::NamedDataBuffer namedDataBuffer4(std::get<TheWorld_Utils::MemoryBuffer>(variant_3));
			namedDataBuffer4.getNames(names);

			buffer_3 = "Buffer 3 old";
			namedDataBuffer.add(buffer_3, nome_Buffer_3);
			variant_3 = namedDataBuffer.getVariant<TheWorld_Utils::MemoryBuffer>(nome_Buffer_3, _flags);
			Assert::IsTrue(not TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_3));
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<TheWorld_Utils::MemoryBuffer>(variant_3));
			buffer_out = std::get<TheWorld_Utils::MemoryBuffer>(namedDataBuffer[nome_Buffer_3]);
			Assert::IsTrue(buffer_out == buffer_3);

			// Wrong types/names should return empty variant
			TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant_1_empty = namedDataBuffer.getVariant<int64_t>(nome_Int32_1, _flags);
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_1_empty));
			variant_1_empty = namedDataBuffer.getVariant<int64_t>("not exists", _flags);
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_1_empty));
			TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant_2_empty = namedDataBuffer.getVariant<int64_t>(nome_String_1, _flags);
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_2_empty));
			TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant_3_empty = namedDataBuffer.getVariant<int64_t>(nome_Buffer_1, _flags);
			Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::emptyVariant(variant_3_empty));

			std::vector<TheWorld_Utils::NamedDataBuffer::NamedDataBufferData> vectValues;
			namedDataBuffer.getValues(vectValues);

			std::map<std::string, TheWorld_Utils::NamedDataBuffer::NamedDataBufferData> mapValues;
			namedDataBuffer.getValues(mapValues);

			for (auto& [name, data] : mapValues)
			{
				TheWorld_Utils::NamedDataBuffer::NamedDataBufferVariant variant = data.v();
				Assert::IsTrue(not TheWorld_Utils::NamedDataBuffer::emptyVariant(variant));

				if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::Int32)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<int32_t>(variant));
					int32_t value = std::get<int32_t>(variant);
					Assert::IsTrue(value == std::get<int32_t>(namedDataBuffer.getVariant<int32_t>(name, _flags)));
					Assert::IsTrue(value == data.get<int32_t>());
					Assert::IsTrue(value == (int32_t)data);		// operator cast to int32_t
					Assert::IsTrue(value == int32_t(data));		// operator cast to int32_t
				}
				else if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::Int64)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<int64_t>(variant));
					int64_t value = std::get<int64_t>(variant);
					Assert::IsTrue(value == std::get<int64_t>(namedDataBuffer.getVariant<int64_t>(name, _flags)));
					Assert::IsTrue(value == data.get<int64_t>());
					Assert::IsTrue(value == (int64_t)data);		// operator cast to int64_t
					Assert::IsTrue(value == int64_t(data));		// operator cast to int64_t
				}
				else if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::Size)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<size_t>(variant));
					size_t value = std::get<size_t>(variant);
					Assert::IsTrue(value == std::get<size_t>(namedDataBuffer.getVariant<size_t>(name, _flags)));
					Assert::IsTrue(value == data.get<size_t>());
					Assert::IsTrue(value == (size_t)data);		// operator cast to size_t
					Assert::IsTrue(value == size_t(data));		// operator cast to size_t
				}
				else if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::Float)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<float>(variant));
					float value = std::get<float>(variant);
					Assert::IsTrue(value == std::get<float>(namedDataBuffer.getVariant<float>(name, _flags)));
					Assert::IsTrue(value == data.get<float>());
					Assert::IsTrue(value == (float)data);		// operator cast to float
					Assert::IsTrue(value == float(data));		// operator cast to float
				}
				else if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::Double)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<double>(variant));
					double value = std::get<double>(variant);
					Assert::IsTrue(value == std::get<double>(namedDataBuffer.getVariant<double>(name, _flags)));
					Assert::IsTrue(value == data.get<double>());
					Assert::IsTrue(value == (double)data);		// operator cast to double
					Assert::IsTrue(value == double(data));		// operator cast to double
				}
				else if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::String)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<std::string>(variant));
					std::string value = std::get<std::string>(variant);
					Assert::IsTrue(value == std::get<std::string>(namedDataBuffer.getVariant<std::string>(name, _flags)));
					Assert::IsTrue(value == data.get<std::string>());
					//value = static_cast<std::string>(data);		// operator cast to std::string
					//Assert::IsTrue(value == (std::string)data);	// operator cast to std::string
					//Assert::IsTrue(value == std::string(data));	// operator cast to std::string
				}
				else if (data.type() == TheWorld_Utils::NamedDataBuffer::Type::Buffer)
				{
					Assert::IsTrue(TheWorld_Utils::NamedDataBuffer::correctType<TheWorld_Utils::MemoryBuffer>(variant));
					TheWorld_Utils::MemoryBuffer value = std::get<TheWorld_Utils::MemoryBuffer>(variant);
					Assert::IsTrue(value == std::get<TheWorld_Utils::MemoryBuffer>(namedDataBuffer.getVariant<TheWorld_Utils::MemoryBuffer>(name, _flags)));
					Assert::IsTrue(value == data.get<TheWorld_Utils::MemoryBuffer>());
					Assert::IsTrue(value == (TheWorld_Utils::MemoryBuffer)data);	// operator cast to TheWorld_Utils::MemoryBuffer
					Assert::IsTrue(value == TheWorld_Utils::MemoryBuffer(data));	// operator cast to TheWorld_Utils::MemoryBuffer
					Assert::IsTrue(value == static_cast<TheWorld_Utils::MemoryBuffer>(data));	// operator cast to TheWorld_Utils::MemoryBuffer
				}
			}
		}

		TEST_METHOD(HalfFloatTest)
		{
			// float to half and back: decimal values are approssimated to the first decimal digit near to 0.0/0.5:
			//		958.0 ==> 958.0
			//		958.1 ==> 958.0
			//		958.2 ==> 958.0
			//		958.3 ==> 958.5
			//		958.4 ==> 958.5

			{
				uint16_t half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.0f);
				float f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.0f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.1f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.0f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.2f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.0f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.24f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.0f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.25f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.0f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.5f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.5f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.74f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 958.5f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(958.75f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 959.0f);

				half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(959.0f);
				f_test = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
				Assert::IsTrue(f_test == 959.0f);
			}
			
			float f = 958.978516f;
			float f_test = 959.0f;
			uint16_t half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			float f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.978f;
			f_test = 959.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.97f;
			f_test = 959.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.9f;
			f_test = 959.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.6f;
			f_test = 958.5f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.61f;
			f_test = 958.5f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.4f;
			f_test = 958.5f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.3f;
			f_test = 958.5f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.2f;
			f_test = 958.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.24f;
			f_test = 958.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.25f;
			f_test = 958.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 958.26f;
			f_test = 958.5f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 959.0f;
			f_test = 959.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 2700.87183f;
			f_test = 2700.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);

			f = 2697.62818f;
			f_test = 2698.0f;
			half = TheWorld_Utils::MeshCacheBuffer::halfFromFloat(f);
			f1 = TheWorld_Utils::MeshCacheBuffer::halfToFloat(half);
			Assert::IsTrue(f1 == f_test);
		}

		TEST_METHOD(Uint16HeightFloatTest)
		{
			float fHeightMinFloat = TheWorld_Utils::MeshCacheBuffer::uint16HeightMinFloat();				// -10922.3330
			float fHeightMaxFloat = TheWorld_Utils::MeshCacheBuffer::uint16HeightMaxFloat();				// 10922.6670

			std::vector<float> testHeights = { -10922.3330f, -10922.0f, -10921.5f, -10921.0f, -10920.5f, -10920.0f, 0.0f, 10920.0f, 10920.5f, 10921.0f, 10921.5f, 10922.0f, 10922.6670f, 2700.87183f, 2700.57183f, 2700.5f, 2700.0f, 2700.3f, 2700.499f };
			std::vector<uint16_t> computedHeightsUint16_1;
			std::vector<float> computedHeightsFloat_1;
			std::vector<uint16_t> computedHeightsUint16_2;
			std::vector<float> computedHeightsFloat_2;
			computedHeightsUint16_1.resize(testHeights.size());
			computedHeightsFloat_1.resize(testHeights.size());
			computedHeightsUint16_2.resize(testHeights.size());
			computedHeightsFloat_2.resize(testHeights.size());
			for (size_t idx = 0; idx < testHeights.size(); ++idx)
			{
				computedHeightsUint16_1[idx] = TheWorld_Utils::MeshCacheBuffer::uint16HeightFromFloat(testHeights[idx]);
				computedHeightsFloat_1[idx] = TheWorld_Utils::MeshCacheBuffer::uint16HeightToFloat(computedHeightsUint16_1[idx]);
				computedHeightsUint16_2[idx] = TheWorld_Utils::MeshCacheBuffer::uint16HeightFromFloat(computedHeightsFloat_1[idx]);
				computedHeightsFloat_2[idx] = TheWorld_Utils::MeshCacheBuffer::uint16HeightToFloat(computedHeightsUint16_2[idx]);
				Assert::IsTrue(computedHeightsUint16_1[idx] == computedHeightsUint16_2[idx]);
				Assert::IsTrue(computedHeightsFloat_1[idx] == computedHeightsFloat_2[idx]);
			}
		}
	};
}
