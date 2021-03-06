#ifndef PROPERTY_TREE_HXX
#define PROPERTY_TREE_HXX 1

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/format.hpp>

using boost::format ;

#include <iostream>
#include <string>

namespace pt = boost::property_tree ;

class PropertyTree : public pt::ptree
{
	public:
		PropertyTree() : pt::ptree() { }

		void setPrefix (const std::string& p_prefix)
		{ m_prefix = p_prefix ; }

		template <typename ValueType> void
			setValue(const std::string& p_key, const ValueType& p_value) 
			{ put(getKey(p_key), p_value) ;}

		template <typename ValueType> ValueType
			getValue (const std::string& p_key, const ValueType& p_defaultValue) const
			{
				boost::optional<ValueType> val =
					get_optional<ValueType>(getKey(p_key)) ;
				if (!val) return p_defaultValue ;
				else      return val.get() ;
			}

		template <typename ValueType> ValueType
			getValue (const std::string& p_key) const
			{ return get<ValueType>(getKey(p_key)) ; }

#if 0
		void setValue (const string& p_key, const date& p_date)
		{
			ostringstream os ;
			os.imbue(locale(cout.getloc(), new date_facet("%B:%d:%Y"))) ;
			os << p_date ;
			put(getKey(p_key), os.str()) ;
		}

		template <> date getValue (const string& p_key) const
		{
			string s = getValue<string>(p_key) ;

			istringstream is ;
			is.imbue(locale(cout.getloc(), new date_input_facet("%B:%d:%Y"))) ;
			is.str(s) ; date d ; is >> d ;

			return d ;
		}
#endif

		void printTree (std::ostream& p_stream = std::cout) const
		{ 
			pt::write_xml (p_stream, static_cast<pt::ptree>(*this), 
					pt::xml_writer_settings<char>(' ', 4)) ; 
		}

	private:
		std::string m_prefix ;

	private:
		string getKey (const string& p_key) const
		{
			if (m_prefix.empty()) return p_key ;
			return (format ("%1%.%2%") % m_prefix % p_key).str() ;
		}
} ;

#endif
