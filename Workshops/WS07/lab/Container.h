#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

namespace sdds
{
	const auto MAX_CHARS = 50;  

	class Container
	{
	private:
		char m_content[MAX_CHARS + 1];  
		int m_capacity;
		int m_contentVolume;
		bool m_validState; 

	protected:
		void setEmpty(); 
		int getCapacity() const;
		int getVolume() const;

	public:
		// Constructor
		Container(const char* content, int capacity, int contentVolume = 0); 
		// Operations
		virtual int operator+=(int value);
		virtual int operator-=(int value);
		// bool type conversion.
		operator bool() const;
		// Methods
		virtual void clear(int capacity, const char* content_desc);
		virtual std::ostream& print(std::ostream& ostr) const;
		virtual std::istream& read(std::istream& istr); 
	};

	// Helper Extraction(Left-shift) and Insertion(Right-shift) Operators respectively
	std::ostream& operator<<(std::ostream& ostr, const Container& container);
	std::istream& operator>>(std::istream& ostr, Container& container);

}  // namespace sdds

#endif   // !SDDS_CONTAINER_H