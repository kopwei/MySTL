namespace mystl
{
	template<typename T1, typename T2>
	struct mypair
	{
		// Type names
		typedef T1 first_type;
		typedef T2 second_type;

		// member
		T1 first;
		T2 second;

		/**
		 * default constructor
		 */
		 mypair() : first(T1()), second(T2()) {}


		 mypair(const T1& a, const T2& b) : first(a), second(b) {}


		 template<typename U, typename V>
		 mypair(const mypair<U, V>& p) : first(p.first), second(p.second){}

		 


		/* data */
	};


}