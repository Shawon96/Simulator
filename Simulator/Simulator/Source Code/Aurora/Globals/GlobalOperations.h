#ifndef GLOBALOPERATIONS_H
#define GLOBALOPERATIONS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <typeinfo>
#include <string>
#include <algorithm>
#include <map>
#include <memory>
#include <stdlib.h> 
#include "Constants.h"
#include "../Errors/ErrorOperations.h"
#include "GlobalDatatypes.h"

/*! \file */ 
/*! A quick define for a debug mode key usage without any big complications. */
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
/*! A quick define for a debug mode key usage without any big complications. */
#define KEY_UP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)
/*! This define will initialize a Direct Draw description struct. */
#define DDRAW_INIT_STRUCT(ddstruct) { memset(&ddstruct,0,sizeof(ddstruct)); ddstruct.dwSize=sizeof(ddstruct); }
/*! Used to delete a DirectX component without any memory leaks. */
#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
/*! Used to delete a DirectX component without any memory leaks. */
#define SAFE_RELEASE(x) if (x != NULL) {x->Release(); x = NULL;}
/*! A quick Win32 MessageBox function caller. */
#define MSG(msg) MessageBox( NULL, msg, "Application Message", MB_OK )	// An windows message box

/*! \brief This builds a 16 bit color value in 5.5.5 format (1-bit alpha mode) */
#define _RGB16BIT555(r,g,b) ((b & 31) + ((g & 31) << 5) + ((r & 31) << 10))
/*! \brief This builds a 16 bit color value in 5.6.5 format (green dominate mode) */
#define _RGB16BIT565(r,g,b) ((b & 31) + ((g & 63) << 5) + ((r & 31) << 11))
/*! \brief This builds a 24 bit color value in 8.8.8 format */
#define _RGB24BIT(a,r,g,b) ((b) + ((g) << 8) + ((r) << 16) )
/*! \brief This builds a 32 bit color value in A.8.8.8 format (8-bit alpha mode) */
#define _RGB32BIT(a,r,g,b) ((b) + ((g) << 8) + ((r) << 16) + ((a) << 24))
//#define MIN(a, b)  (((a) < (b)) ? (a) : (b)) 
//#define MAX(a, b)  (((a) > (b)) ? (a) : (b)) 
//#define SWAP(a,b,t) {t=a; a=b; b=t;}

extern "C" inline unsigned int RGB16BIT555(unsigned int r, unsigned int g, unsigned int b);
extern "C" inline unsigned int RGB16BIT565(unsigned int r, unsigned int g, unsigned int b);

/*!
 This function will compare two STL string and return true if they are identical or false if not.
 */
extern "C" bool CompareStrings(std::string strOne, std::string strTwo);
/*!
 
 This function will determine if a given STL string is just a number with no ASCII nor UNICODE chars.
 */
extern "C" bool IsStringPlainNumber(std::string str);

namespace Aurora
{
	/*!
	Namespace: DataTypes

	\brief This namespace holds the engines different datatypes that are used allover the project. It holds datatypes from basic types supported by C/C++ to complex struct, enumerations and STL specific types.
	*/
	namespace Global
	{
		// Original implementation(now modified with variadic templates) from: http://geekswithblogs.net/raccoon_tim/archive/2011/09/28/lambdas-and-events-in-c.aspx
		// TODO: Typesafety check
		template<typename... T1>
		class Event
		{
		public:
			typedef std::function<void(T1...)> Func;

		public:
			void Call(T1 ...arg)
			{
				for (auto i = m_handlers.begin(); i != m_handlers.end(); i++)
				{
					(*i)(arg...);
				}
			}

			void operator ()(T1 ...arg)
			{
				Call(arg...);
			}

			Event& operator += (Func f)
			{
				if (typeid(f) != typeid(Func))
					throw std::bad_function_call("Error in type");

				m_handlers.push_back(f);
				return *this;
			}

			Event& operator -= (Func f)
			{
				for (auto i = m_handlers.begin(); i != m_handlers.end(); i++)
				{
					if ((*i).target<void(T1)>() == f.target<void(T1)>())
					{
						m_handlers.erase(i);
						break;
					}
				}

				return *this;
			}

		private:
			std::vector<Func> m_handlers;
		};

		/*template<typename returnType, typename T1>
		class EventReturnType
		{
		public:
			typedef std::function<returnType(T1)> Func;

		public:
			returnType Call(T1 arg)
			{
				for (auto i = m_handlers.begin(); i != m_handlers.end(); i++)
				{
					return((returnType)(*i)(arg));
				}
			}

			returnType operator ()(T1 arg)
			{
				return(Call(arg));
			}

			EventReturnType& operator += (Func f)
			{
				if (typeid(f) != typeid(Func))
					throw std::bad_function_call("Error in type");

				m_handlers.push_back(f);
				return *this;
			}

			EventReturnType& operator -= (Func f)
			{
				for (auto i = m_handlers.begin(); i != m_handlers.end(); i++)
				{
					if ((*i).target<returnType(T1)>() == f.target<returnType(T1)>())
					{
						m_handlers.erase(i);
						break;
					}
				}

				return *this;
			}

		private:
			std::vector<Func> m_handlers;
		};*/

		

		//###################################################################################
		// Code for lambda callbacks from: http://meh.schizofreni.co/programming/magic/2013/01/23/function-pointer-from-lambda.html
		// START
		//###################################################################################
		template <typename Function>
		struct function_traits
			: public function_traits < decltype(&Function::operator()) >
		{};

		template <typename ClassType, typename ReturnType, typename... Args>
		struct function_traits < ReturnType(ClassType::*)(Args...) const >
		{
			typedef ReturnType(*pointer)(Args...);
			typedef std::function<ReturnType(Args...)> function;
		};

		template <typename Function>
		typename function_traits<Function>::pointer
			to_function_pointer(Function& lambda)
		{
			return static_cast<typename function_traits<Function>::pointer>(lambda);
		}

		template <typename Function>
		typename function_traits<Function>::function
			to_function(Function& lambda)
		{
			return static_cast<typename function_traits<Function>::function>(lambda);
		}

		class Callbacks final
		{
			struct Callback final
			{
				void*                 function;
				const std::type_info* signature;
			};

		public:
			Callbacks(void)
			{
			}

			~Callbacks(void)
			{
				for (auto entry : _callbacks) {
					delete static_cast<std::function<void()>*>(entry.second->function);
				}
			}

			template <typename Function>
			void
				add(std::string name, Function lambda)
			{
				if (_callbacks.find(name) != _callbacks.end()) {
					throw std::invalid_argument("the callback already exists");
				}

				auto function = new decltype(to_function(lambda))(to_function(lambda));

				this->_callbacks.emplace(name, std::make_shared<Callback>());

				_callbacks[name]->function = static_cast<void*>(function);
				_callbacks[name]->signature = &typeid(function);
			}

			void
				remove(std::string name)
			{
				if (_callbacks.find(name) == _callbacks.end()) {
					return;
				}

				delete static_cast<std::function<void()>*>(_callbacks[name]->function);
			}

			/*template <typename ...Args>
			void
				call(std::string name, Args... args)
			{
				auto callback = _callbacks.at(name);
				auto function = static_cast<std::function<void(Args...)>*>(
					callback->function);

				CCLOG("Callback type id: %s", *(callback->signature));
				CCLOG("Function type id: %s", typeid(function));

				if (typeid(function) != *(callback->signature)) {
					throw std::bad_typeid();
				}

				(*function)(args...);
			}*/

			template <typename returntype, typename ...Args >
			auto
				call(std::string name,returntype returnType, Args ...args) -> decltype(returnType)
			{
				auto callback = _callbacks.at(name);
				auto function = static_cast<std::function<decltype(returnType)(Args...)>*>(
					callback->function);

				CCLOG("Callback type id: %s", callback->signature->name());
				CCLOG("Function type id: %s", typeid(function).name());

				if (typeid(function) != *(callback->signature)) {
					throw std::bad_typeid();
				}

				auto returnValue = (*function)(args...);

				return(returnValue);
			}

		private:
			std::map<std::string, std::shared_ptr<Callback>> _callbacks;
		};

		//###################################################################################
		// Code for lambda callbacks from: http://meh.schizofreni.co/programming/magic/2013/01/23/function-pointer-from-lambda.html
		// END
		//###################################################################################
	};

};

#endif