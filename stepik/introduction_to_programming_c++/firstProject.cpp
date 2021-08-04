#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <climits>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

// Электронные часы
// 
// #include <iostream>
//
//using namespace std;
//
//int main() {
//    int N, H, M, m, S, s;
//    cin >> N;
//    H = N / 3600 % 24;
//    M = N % 3600 / 60 / 10;
//    m = N % 3600 / 60 % 10;
//    S = N % 3600 % 60 / 10;
//    s = N % 3600 % 60 % 10;
//    cout << H << ":" << M << m << ":" << S << s;
//}
// 
// 
// 
//int main()
//{
//	const int sind = 86400;
//	const int sinh = 3600;
//	const int sinm = 60;
//	const int minh = 60;
//	const int hind = 24;
//
//	int n = 129700;
//	int d, h, m1, m2, s1, s2;
//	d = n / sind;
//	int newSec;
//	newSec = n - d * hind * sinh;
//	h = newSec / sinh;
//	newSec -= h * sinh;
//	m1 = newSec / minh / 10;
//	m2 = newSec / minh % 10;
//	s1 = (newSec - m1 * 10 * minh - m2 * minh) / 10;
//	s2 = (newSec - m1 * 10 * minh - m2 * minh) % 10;
//	cout << h << ":" << m1 << m2 << ":" << s1 << s2;
//	return 0;
//}


// сравнить три числа и вывести номер наибольшего
//int main() {
//    int a, b, c;
//    cin >> a >> b >> c;
//    if (a >= b && a >= c) 
//        cout << 1;
//    else if (b >= a && b >= c)
//        cout << 2;
//    else
//        cout << 3;
//    return 0;
//}

// решил ход королём
//int main() {
//    int x1, y1, x2, y2;
//    cin >> x1 >> y1 >> x2 >> y2;
//    if (abs(x1 - x2) <= 1)
//    {
//        if (abs(y1 - y2) <= 1)
//            cout << "YES";
//        else
//            cout << "NO";
//    }
//    else
//        cout << "NO";
//    return 0;
//}

// Решил ход слона
//int main() {
//    int x1, y1, x2, y2;
//    while (true)
//    {
//        cin >> x1 >> y1 >> x2 >> y2;
//        if (abs(x1 - x2) == abs(y1 - y2))
//            cout << "YES";
//        else
//            cout << "NO";
//
//    }
//    return 0;
//}

// Решил ход ферзя
//int main()
//{
//	int x1, y1, x2, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//	if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
//		cout << "YES";
//	else
//		cout << "NO";
//	return 0;
//}

//ход коня
//int main()
//{
//	int x1, y1, x2, y2;
//	while (true)
//	{
//
//		cin >> x1 >> y1 >> x2 >> y2;
//		int dx = abs(x1 - x2);
//		int dy = abs(y1 - y2);
//		if (dx == 1 && dy == 2 || dy == 1 && dx == 2)
//			cout << "YES";
//		else
//			cout << "NO";
//	/*	if (dx > 2 && dy > 2 && dx == 0 || dy == 0)
//			cout << "NO";
//		else if (dx == 1 && dy == 2)
//			cout << "YES";
//		else if (dy == 1 && dx == 2)
//			cout << "YES";*/
//	}
//		return 0;
//}

// задача про деление плитки шоколада
//int main()
//{
//	int n, m, k;
//	while (true)
//	{
//		cin >> n >> m >> k;
//		if (n * m / k >= 1)
//		{
//			if (m == k || n == k)
//				cout << "YES";
//			if )
//		}
//	}
//
//	return 0;
//}

//задача про бассейн решил
//int main()
//{
//	while (true)
//	{
//		int n, m, x, y;
//		cin >> n >> m >> x >> y;
//		
//		if (m < n)
//		{
//			int temp;
//			temp = m;
//			m = n;
//			n = temp;
//		}
//
//
//		if (x == 0)
//			cout << x;
//		else if (y == 0)
//			cout << y;
//		else
//		{
//			int _x, _y;
//			_x = n - x;
//			_y = m - y;
//			int minx, miny;
//			if (x <= _x)
//				minx = x;
//			else
//				minx = _x;
//			if (y <= _y)
//				miny = y;
//			else
//				miny = _y;
//			if (minx <= miny)
//				cout << minx;
//			else
//				cout << miny;
//		}
//	}
//	return 0;
//}

// решено, расположить числа в порядке возрастания
//int main()
//{
//	int a, b, c;
//	int temp;
//	while (true)
//	{
//		cin >> a >> b >> c;
//		if (b >= c)
//		{
//			temp = c;
//			c = b;
//			b = temp;
//		}
//		if (a >= c)
//		{
//			temp = c;
//			c = a;
//			a = temp;
//		}
//		if (a >= b)
//		{
//			temp = b;
//			b = a;
//			a = temp;
//		}
//		cout << a << " " << b << " " << c;
//	}
//	return 0;
//}

//int main()
//{
//	int a1, b1, c1, a2, b2, c2;
//	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
//	if (a1 == a2 && b1 == b2 && c1 == c2)
//		cout << "Boxes are equal";
//	else if (a1 >= a2 && b1 >= b2 && c1 >= c2)
//	{
//		int t = a1;
//		a1 = a2;
//		a2 = t;
//		t = b1;
//		b1 = b2;
//		b2 = t;
//		t = c1;
//		c1 = c2;
//		c2 = t;
//	}
//	return 0;
//}

//int main()
//{
//	int now, max = 0;
//	cin >> now;
//	while (now != 0)
//	{
//		if (now >= max)
//			max = now;
//		cin >> now;
//	}
//	cout << max;
//	return 0;
//}

// последовательность Фиббоначи до n
//int main()
//{
//    int i = 0, a, f = 0, g = 1;
//    cin >> a;
//    while (i < a)
//    {
//        f = f + g;
//        g = f - g;
//        if (a == g)
//        {
//            break;
//        }
//        i++;
//    }
//    cout << i;
//	return 0;
//}

//int main() {
//    int n;
//    cin >> n;
//    int m = 1;
//    while (m < n)
//    {
//        m *= 2;
//
//    }
//    if (m == n)
//        cout << "YES";
//    else
//        cout << "NO";
//    return 0;
//}

//int main() {
//    int i = 0, a, f = 0, g = 1;
//    cin >> a;
//    while (true)
//    {
//        i++;
//        f = f + g;
//        g = f - g;
//        if (f >= a)
//        {
//            break;
//        }
//    }
//    if (a == g || a == f)
//        cout << i;
//    else
//        cout << -1;
//    return 0;
//}

//int main()
//{
//	double x = 0.0;
//	cin >> x;
//	x = x % 2.0;
//	cout << x;
//	return 0;
//}


//int main() {
//    int p, rub, kop;
//    cin >> p >> rub >> kop;
//    kop += rub * 100;
//    kop += kop * p / 100;
//    if (kop > 100)
//    {
//        rub = kop / 100;
//        kop %= 100;
//    }
//    cout << rub << " " << kop;
//    return 0;
//}

//int main() {
//    int now, sum = 0, counter = 0;
//    cin >> now;
//    while (now)
//    {
//        counter++;
//        sum += now;
//        cin >> now;
//    }
//    double m = (double) sum / counter;
//    cout << setprecision(11) << fixed;
//    cout << m;
//    return 0;
//}

//int main() {
//    double a, b, c, root1, root2;
//    cin >> a >> b >> c;
//    double D = b * b -4 * a * c;
//    if (D >= 0)
//    {
//        root1 = (-b - sqrt(D)) / (2 * a);
//        root2 = (-b + sqrt(D)) / (2 * a);
//        if (root1 == root2)
//            cout << root1;
//        else
//        {
//            if (root2 > root1)
//                cout << root1 << " " << root2;
//            else
//                cout << root2 << " " << root1;
//        }
//    }
//    else
//        ;
//    return 0;
//}

// решил необязательно квадратное уравнение с выводом количества корней
//int main() {
//    double a, b, c;
//    cin >> a >> b >> c;
//    if (a == 0 && b == 0 && c == 0)
//    {
//        cout << 3;
//        return 0;
//    }
//    if (a == 0 && b == 0 && c != 0)
//    {
//        cout << 0;
//        return 0;
//    }
//    if (a != 0) 
//    {
//        double d;
//        d = b * b - 4 * a * c;
//        if (d >= 0)
//        {
//            double root1 = ((-b) - sqrt(d)) / (2 * a);
//            if (d > 0)
//            {
//                double root2 = ((-b) + sqrt(d)) / (2 * a);
//                if (root1 > root2)
//                {
//                    double temp = root1;
//                    root1 = root2;
//                    root2 = temp;
//                }
//                cout << 2 << " " << root1 << " " << root2;
//                return 0;
//            }
//            cout << 1 << " " << root1;
//        }
//        else
//            cout << 0;
//    }
//    else
//    {
//        double root = -c / b;
//        cout << 1 << " " << root;
//    }
//
//    return 0;
//}

//int main() {
//    double a, b, c, d, e, f;
//    cin >> a >> b >> c >> d >> e >> f;
//    double det = a * d - b * c;
//    double dx = e * d - b * f;
//    double dy = a * f - e * c;
//    cout << dx / det << " " << dy / det;
//    return 0;
//}

//int main()
//{
//	double a, b, c, d, e, f;
//	cin >> a >> b >> c >> d >> e >> f;
//	double D = a * d - b * c;
//	if (D != 0) // если имеется единственное решение
//	{
//		double Dx = e * d - b * f;
//		double Dy = a * f - e * c;
//		cout << 2 << Dx / D << " " << Dy / D;
//	}
//	else
//	{
//
//
//	}
//}

// Если система не имеет решений, то программа должна вывести единственное число 0.
// Если система имеет бесконечно много решений, каждое из которых имеет вид y = kx + n, то программа должна вывести число 1, а затем значения k и n.
// Если система имеет единственное решение(x0, y0), то программа должна вывести число 2, а затем значения x0 и y0
// Если система имеет бесконечно много решений вида x = x0, y — любое, то программа должна вывести число 3, а затем значение x0.
// Если система имеет бесконечно много решений вида y = y0, x — любое, то программа должна вывести число 4, а затем значение y0.
// Если любая пара чисел(x, y)  является решением, то программа должна вывести число 5.



//int main() {
//    int n;
//    int now;
//    vector <int> v;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> now;
//        v.push_back(now);
//    }
//    int counter = 0;
//    for (auto now : v)
//        if (now > 0)
//            counter++;
//    cout << counter;
//    return 0;
//}

//int main() {
//    int n;
//    cin >> n;
//    int now;
//    vector <int> v;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> now;
//        v.push_back(now);
//    }
//    for (int i = 1; i < n; i++)
//    {
//        if (v[i] < 0 && v[i - 1] < 0 || v[i] > 0 && v[i - 1] > 0)
//        {
//            if (v[i] >= v[i - 1])
//                cout << v[i - 1] << " " << v[i] << " ";
//            else
//                cout << v[i] << " " << v[i - 1] << " ";
//            break;
//        }
//    }
//    return 0;
//}

//int main() {
//    int n;
//    cin >> n;
//    vector <int> v;
//    int now;
//    int min = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> now;
//        v.push_back(now);
//        if (now > 0)
//            min = now;
//    }
//    for (auto cur : v)
//    {
//        if (cur > 0 && cur <= min)
//            min = cur;
//    }
//    cout << min;
//    return 0;
//}

//int main() {
//    int n, now;
//    cin >> n;
//    vector <int> v;
//    int minodd = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> now;
//        v.push_back(now);
//        if (now % 2 != 0)
//            minodd = now;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (v[i] % 2 != 0 && v[i] < minodd)
//            minodd = v[i];
//    }
//    cout << minodd;
//    return 0;
//}


//int main() {
//    int n, counter = 0;
//    vector <int> root;
//    int lastU = 0;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int now;
//        cin >> now;
//        if (now != lastU)
//        {
//            lastU = now;
//            counter++;
//        }
//    }
//    cout << counter;
//    return 0;
//}



//int main() {
//    int n, counter = 0;
//    cin >> n;
//    vector <int> v;
//    for (int i = 0; i < n; i++)
//    {
//        int now;
//        cin >> now;
//        v.push_back(now);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//            if (v[i] == v[j])
//                counter++;
//    }
//    cout << counter;
//    return 0;
//}


//int main()
//{
//    int n;
//    cin >> n;
//    vector <int> v;
//    for (int i = 0; i < n; i++)
//    {
//        int now;
//        cin >> now;
//        v.push_back(now);
//    }
//    vector <int> u;
//    for (int i = 0; i < n; i++)
//    {
//        int count = 0;
//        for (int j = 0; j < n; j++)
//        {
//            if (v[i] == v[j])
//                count++;
//        }
//        if (count == 1)
//        {
//            u.push_back(v[i]);
//        }
//    }
//    for (auto now : u)
//        cout << now << " ";
//    return 0;
//}

//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector <int> v;
//    for (int i = 0; i < k * 2; i++)
//    {
//        int now;
//        cin >> now;
//        v.push_back(now);
//    }
//    vector <char> kegli(n);
//
//    for (int i = 0; i < n; i++)
//        kegli[i] = 'I';
//
//    for (int i = 0; i < k * 2; i += 2)
//    {
//        for (int j = v[i]-1; j <= v[i + 1]-1; j++)
//            kegli[j] = '.';
//    }
//
//    for (auto now : kegli)
//        cout << now;
//    return 0;
//}

//int main()
//{
//    vector <int> x;
//    vector <int> y;
//    for (int i = 0; i < 8; i++)
//    {
//        int curx;
//        cin >> curx;
//        x.push_back(curx);
//        int cury;
//        cin >> cury;
//        y.push_back(cury);
//    }
//    int counterx = 0, countery = 0, counterd = 0;
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            if (x[i] == x[j])
//            {
//                counterx++;
//                if (counterx > 1)
//                    break;
//            }
//            if (y[i] == y[j])
//            {
//                countery++;
//                if (countery > 1)
//                    break;
//            }
//            if (abs(x[i] - x[j]) == abs(y[i] - y[j]))
//            {
//                counterd++;
//                if (counterd > 1)
//                    break;
//            }
//        }
//        if (counterx > 1 || countery > 1 || counterd > 1)
//        {
//            cout << "YES";
//            return 0;
//        }
//        counterx = countery = counterd = 0;
//    }
//     cout << "NO";
//     return 0;
//}

//int main() {
//    int n, m;
//    cin >> n >> m;
//    int a[100][100];
//    int max = INT_MIN;
//    int remi = 0, remj = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> a[i][j];
//            if (max < a[i][j])
//            {
//                max = a[i][j];
//                remi = i;
//                remj = j;
//            }
//        }
//    }
//    cout << remi << " " << remj;
//    return 0;
//}

// Решил снежинка
//int main()
//{
//	int n;
//	cin >> n;
//	char c[15][15];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			c[i][j] = '.';
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i == j || i + j == n - 1 || i == n / 2 || j == n / 2)
//				c[i][j] = '*';
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << c[i][j];
//		cout << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//	int a[100][100];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			a[i][j] = abs(i - j);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << a[i][j] << " ";
//		cout << endl;
//	}
//	return 0;
//}

//int main() {
//    int n, m;
//    cin >> n >> m;
//    int arr[100][100];
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> arr[i][j];
//    int y1, y2;
//    cin >> y1 >> y2;
//    for (int i = 0; i < n; i++)
//    {
//        int temp = arr[i][y1];
//        arr[i][y1] = arr[i][y2];
//        arr[i][y2] = temp;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            cout << arr[i][j] << " ";
//        cout << endl;
//    }
//    return 0;
//}

//int main() {
//    int n;
//    cin >> n;
//    int a[10][10];
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            cin >> a[i][j];
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            if (a[i][j] != a[j][i])
//            {
//                cout << "NO";
//                return 0;
//            }
//    cout << "YES";
//    return 0;
//}

//int main() {
//    int n;
//    cin >> n;
//    int a[10][10];
//
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            cin >> a[i][j];
//    int k;
//    cin >> k;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//            if (i - j == k)
//                cout << a[i][j] << " ";
//    }
//    return 0;
//}


//int main() {
//    int n, m;
//    cin >> n >> m;
//    int a[20][20];
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> a[i][j];
//    int k, counter = 0;
//    cin >> k;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (!a[i][j])
//                counter++;
//            else
//            {
//                counter = 0;
//                continue;
//            }
//            if (counter == k)
//            {
//                cout << i + 1;
//                return 0;
//            }
//        }
//        counter = 0;
//    }
//    cout << 0;
//    return 0;
//}


//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int a[100][100];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			cin >> a[i][j];
//	
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = n - 1; j >= 0; j--)
//			cout << a[j][i] << " ";
//		cout << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int a[30][30];
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (i % 2 == 0)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				count++;
//				a[i][j] = count;
//			}
//		}
//		else
//		{
//			for (int j = m - 1; j >= 0; j--)
//			{
//				count++;
//				a[i][j] = count;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cout << setw(4) << a[i][j];
//		cout << endl;
//	}
//	return 0;
//}


// 1.8 Заполнить диагонали
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector <vector <int>> a(n, vector <int>(m));
//    int counter = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            counter += j * 2;
//            a[j][i] = counter;
//        }
//        counter -= m;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            cout << setw(4) << a[i][j];
//        cout << endl;
//    }
//    return 0;
//}

// Решил, заполнить в щахматном порядке
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector <vector <int>> a(n, vector <int>(m));
//	int counter = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if ((i + j) % 2 == 0)
//			{
//				counter++;
//				a[i][j] = counter;
//			}
//			else
//				a[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            cout << setw(4) << a[i][j];
//        cout << endl;
//    }
//	return 0;
//}


//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector <vector <int>> a(n, vector <int>(m));
//	int counter = 0, cy = 0, cx = 0;
//	int cm = m, cn = n;
//	bool stop = false;
//	for (int i = 0; i < cn; i++)
//	{
//		// слева направо
//		for (int j = 0; j < cm; j++)
//		{
//
//			counter++;
//			a[i][j + cy] = counter;
//		}
//		cy++;
//		//сверху вниз
//		for (int k = 0; k < cn - cy; k++)
//		{
//			if (counter == n * m)
//			{
//				stop = true;
//				break;
//			}
//			counter++;
//			a[k + 1][cm - 1] = counter;
//		}
//		cn--;
//		cm--;
//		// справа налево
//		for (int z = cm - 1; z >= i; z--)
//		{
//			if (counter == n * m)
//			{
//				stop = true;
//				break;
//			}
//			counter++;
//			a[cn][z] = counter;
//		}
//		// снизу вверх
//		for (int s = cn - cy; s >= cy; s--)
//		{
//			if (counter == n * m)
//			{
//				stop = true;
//				break;
//			}
//				counter++;
//				a[s][i] = counter;
//		}
//		cm--;
//		if (stop)
//			break;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cout << setw(4) << a[i][j];
//		cout << endl;
//	}
//
//	return 0;
//}


//1.9 Функции и рекурсия
//Напишите функцию min(a, b), вычисляющую минимум двух чисел.Затем напишите функцию min4(a, b, c, d), вычисляющую минимум 4 чисел с помощью функции min. Считайте четыре целых числа и выведите их минимум.
//Формат входных данных
//Вводятся четыре целых числа.

//int min(int x1, int x2)
//{
//	if (x1 > x2)
//	{
//		x1 = x2;
//	}
//	return x1;
//}
//
//int min4(int x1, int x2, int x3, int x4)
//{
//	x1 = min(x1, x2);
//	x1 = min(x1, x3);
//	x1 = min(x1, x4);
//	return x1;
//}
//
//int main()
//{
//	int a, b, c, d;
//
//	cin >> a >> b >> c >> d;
//	cout << min4(a, b, c, d);
//	return 0;
//}

//Даны четыре действительных числа : x1, y1, x2, y2.Напишите функцию distance(x1, y1, x2, y2), вычисляющую расстояние между точкой(x1.y1) и(x2, y2).Считайте четыре действительных числа и выведите результат работы этой функции.
//Формат входных данных
//Вводятся четыре действительных числа.

//double distance(double x1, double y1, double x2, double y2)
//{
//	return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
//}
//
//int main()
//{
//	double x1, y1, x2, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//	cout << distance(x1, y1, x2, y2);
//	return 0;
//}

//Даны два действительных числа x и y.Проверьте, принадлежит ли точка с координатами(x, y) заштрихованному квадрату(включая его границу).Если точка принадлежит квадрату, выведите слово YES, иначе выведите слово NO.На рисунке сетка проведена с шагом 1.
//Решение должно содержать функцию IsPointInSquare(x, y), возвращающую true, если точка принадлежит квадрату и false, 
//если не принадлежит.Основная программа должна считать координаты точки, вызвать функцию IsPointInSquare и в зависимости от возвращенного значения вывести на экран необходимое сообщение.
//Функция IsPointInSquare не должна содержать инструкцию if.

//bool IsPointInSquare(double x, double y)
//{
//	return (x >= -1 && x <= 1 && y >= -1 && y <= 1);
//}
//
//int main()
//{
//	double x, y;
//	cin >> x >> y;
//
//	if (IsPointInSquare(x, y))
//		cout << "YES";
//	else
//		cout << "NO";
//
//	return 0;
//}

// Такая же задача, но ромб

//bool IsPointInSquare(double x, double y)
//{
//	return (abs(x) + abs(y) <= 1);
//}
//
//int main()
//{
//	double x, y;
//	cin >> x >> y;
//
//	if (IsPointInSquare(x, y))
//		cout << "YES";
//	else
//		cout << "NO";
//
//	return 0;
//}

// Такая же, но с окружностью
//bool IsPointInCircle(double x, double y, double xc, double yc, double r)
//{
//	return ((x - xc) * (x - xc) + (y - yc) * (y - yc) <= r * r);
//}
//
//int main()
//{
//	double x, y, xc, yc, r;
//	cin >> x >> y >> xc >> yc >> r;
//
//	if (IsPointInCircle(x, y, xc, yc, r))
//		cout << "YES";
//	else
//		cout << "NO";
//	return 0;
//}

// Такая же, но есть окружность и две прямые
//bool IsPointInArea(double x, double y)
//{
//	int xc = -1, yc = 1, r = 2;
//	return ((x - xc) * (x - xc) + (y - yc) * (y - yc) <= r * r && y >= -x && y >= 2 + 2 * x
//		|| (x - xc) * (x - xc) + (y - yc) * (y - yc) >= r * r && y <= -x && y <= 2 + 2 * x);
//}
//
//int main()
//{
//	double x, y, xc, yc, r;
//	cin >> x >> y;
//
//	if (IsPointInArea(x, y))
//		cout << "YES";
//	else
//		cout << "NO";
//	return 0;
//}


//Решил  Рекурсия, возведение в степень
//double power(double b, int p)
//{
//	if (p == 0)
//		return 1;
//	
//	if (p > 0)
//		return b * power(b, p - 1);
//	else
//		return 1 / b * power(b, p + 1);
//}
//
//int main()
//{
//	double a;
//	int n;
//	cin >> a >> n;
//	cout << power(a, n);
//	return 0;
//}

// Наименьший делитель
//Дано натуральное число n > 1. Выведите его наименьший делитель, отличный от 1.
//Решение оформите в виде функции MinDivisor(n).Количество операций в программе должно быть пропорционально корню из n.
//Указание.Если у числа n нет делителя, меньшего n, то число n — простое и ответом будет само число n.

//int MinDivisor(int n)
//{
//	for (int i = 2, isqrt = sqrt(n); i <= isqrt; i++)
//		if (i * i <= n)
//			if (n % i == 0)
//				return i;
//	return n;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << MinDivisor(n);
//	return 0;
//}

// Определить является ли число простым
//int IsPrime(int n)
//{
//	for (int i = 2, isqrt = sqrt(n); i <= isqrt; i++)
//		if (i * i <= n)
//			if (n % i == 0)
//				return false;
//	return true;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	if (IsPrime(n))
//		cout << "YES";
//	else
//		cout << "NO";
//	return 0;
//}

// считывание и сложение до 0 без цикла
//int adder()
//{
//    int now;
//    cin >> now;
//    if (now)
//        return now + adder();
//    return 0;
//}
//int main() {
//    cout << adder();
//    return 0;
//}

//функция fib(n) возвращает n-е число Фибоначчи
//int fib(int n)
//{
//    int count = 1;
//    if (n > 2)
//        return fib(n - 1) + fib(n - 2);
//    else
//        return 1;
//}
//int main() {
//    int n;
//    cin >> n;
//    cout << fib(n);
//    return 0;
//}

//int main() {
//    char n;
//    cin >> n;
//    if (n >= 0 && n <= 9)
//        cout << "yes";
//    else
//        cout << "no";
//    return 0;
//}

//int main() {
//    char c;
//    cin >> c;
//    if (c >= 'a' && c <= 'z')
//        cout << (char)('A' + c - 'a');
//    else if (c >= 'A' && c <= 'Z')
//        cout << (char)(c - 'A' + 'a');
//    else
//        cout << (char)c;
//    return 0;
//}


//int main()
//{
//	string str;
//	getline(cin, str);
//	int counter = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		i = str.find(' ', i);
//		if (i != -1)
//			counter++;
//		else
//			break;
//	}
//	cout << counter + 1;
//	return 0;
//}

//int main() {
//    string str;
//    cin >> str;
//    for (int i = 0; i < str.size() / 2; i++)
//    {
//        if (str[i] != str[str.size() - i - 1])
//        {
//            cout << "no";
//            return 0;
//        }
//    }
//    cout << "yes";
//    return 0;
//}

//Во входной строке записана последовательность чисел через пробел.Для каждого числа выведите слово YES(в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.
//Входные данные
//Вводится число N - количество элементов списка, а затем N чисел.
// Вариант 1
//int main()
//{
//	int n;
//	cin >> n;
//	set <int> a;
//	vector <int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int now;
//		cin >> now;
//		v.push_back(now);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (!a.insert(v[i]).second)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//
//	}
//	return 0;
//}

// Вариант 2
//int main()
//{
//	int n;
//	cin >> n;
//	set <int> s;
//	int now;
//	int i = 0;
//	while (i < n && cin >> now)
//	{
//		i++;
//		if (!s.insert(now).second)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//	return 0;
//}


//﻿Даны два списка чисел, которые могут содержать до 100000 чисел каждый. Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором.
//Входные данные
//Вводится число N - количество элементов первого списка, а затем N чисел первого списка.
//Затем вводится число M - количество элементов второго списка, а затем M чисел второго списка.


// Вариант 1
//void main()
//{
//	int n;
//	cin >> n;
//	set <int> s1;
//	set <int> s2;
//	for (int i = 0, now; i < n; i++)
//	{
//		cin >> now;
//		s1.insert(now);
//	}
//	int m;
//	cin >> m;
//	for (int i = 0, now; i < m; i++)
//	{
//		cin >> now;
//		s2.insert(now);
//	}
//	int cnt = 0;
//	for (auto cur : s1)
//	{
//		if (s2.find(cur) != s2.end())
//		{
//			cnt++;
//		}
//	}
//	cout << cnt;
//}

// Вариант 2
//int main()
//{
//	int n;
//	cin >> n;
//	set <int> s;
//	for (int i = 0, now; i < n; i++)
//	{
//		cin >> now;
//		s.insert(now);
//	}
//	int m;
//	cin >> m;
//	for (int i = 0, now; i < m; i++)
//	{
//		cin >> now;
//		s.insert(now);
//	}
//	cout << ((m + n) - s.size());
//	return 0;
//}

//Даны два списка чисел, которые могут содержать до 100000 чисел каждый.Выведите все числа, которые входят как в первый, так и во второй список в порядке возрастания.
//Входные данные
//Вводится число N - количество элементов первого списка, а затем N чисел первого списка.
//Затем вводится число M - количество элементов второго списка, а затем M чисел второго списка.
//
//int main() {
//    int n;
//    cin >> n;
//    set <int> s1;
//    for (int i = 0, now; i < n; i++)
//    {
//        cin >> now;
//        s1.insert(now);
//    }
//    int m;
//    cin >> m;
//    set <int> s2;
//    for (int i = 0, now; i < m; i++)
//    {
//        cin >> now;
//        s2.insert(now);
//    }
//    for (auto cur : s1)
//    {
//        if (s2.find(cur) != s2.end())
//            cout << cur << " ";
//    }
//    return 0;
//}

//Вам дан словарь, состоящий из пар слов.Каждое слово является синонимом к парному ему слову.Все слова в словаре различны.Для одного данного слова определите его синоним.
//Входные данные
//Программа получает на вход количество пар синонимов N.Далее следует N строк, каждая строка содержит ровно два слова - синонима.После этого следует одно слово.
//Выходные данные
//Программа должна вывести синоним к данному слову.

//int main()
//{
//	int n;
//	cin >> n;
//	map <string, string> dict;
//	for (int i = 0; i < n; i++)
//	{
//		string key, val;
//		cin >> key >> val;
//		dict.insert(make_pair(key, val));
//	}
//	string foo;
//	cin >> foo;
//	for (auto now : dict)
//	{
//		if (foo == now.first)
//			cout << now.second;
//		else if (foo == now.second)
//			cout << now.first;
//	}
//	return 0;
//}

// обычная сортировка с помощью STL (algorithm)
//int main()
//{
//	int n;
//	cin >> n;
//	vector <int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//	for (auto now : a)
//		cout << now << " ";
//	return 0;
//}

// упорядочить массив и вывести номера элементов в том порядке, в котором они стояли в исходном массиве.

//int main()
//{
//	int n;
//	cin >> n;
//	vector <pair <int, int>> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		a[i] = { temp, i };
//	}
//	sort(a.begin(), a.end());
//	for (auto now : a)
//		cout << now.second << " ";
//	return 0;
//}

// упорядочить по убыванию
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <pair <int, int>> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		a[i] = { temp, i };
//	}
//	sort(a.begin(), a.end());
//	reverse(a.begin(), a.end());
//	for (auto now : a)
//		cout << now.first << " ";
//	return 0;
//}


// Создали вектор структур, заполнили вектор структур, написали КАК соритровать вектор структур (соритруем по возрастанию роста)
//struct man
//{
//	int height;
//	string name;
//};
//
//bool cmp(man a, man b)
//{
//	return a.height < b.height;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <man> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		string s_temp;
//		cin >> temp >> s_temp;
//		man struct_temp;
//		struct_temp.height = temp;
//		struct_temp.name = s_temp;
//		a[i] = struct_temp;
//	}
//	sort(a.begin(), a.end(), cmp);
//	for (auto now : a)
//		cout << now.name << endl;
//	return 0;
//}


// Люди выстроились в ряд, но если люди с одинаковым ростом, оставить их в исходной последовательности УСТОЙЧИВАЯ СОРТИРОВКА

//struct man
//{
//	int height;
//	string name;
//};
//
//bool cmp(man a, man b)
//{
//	return a.height < b.height;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <man> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		string s_temp;
//		cin >> temp >> s_temp;
//		man struct_temp;
//		struct_temp.height = temp;
//		struct_temp.name = s_temp;
//		a[i] = struct_temp;
//	}
//	stable_sort(a.begin(), a.end(), cmp);
//	for (auto now : a)
//		cout << now.name << endl;
//	return 0;
//}

// Поиск медианы (отсортировать по возрастанию и взять ЭЛЕМЕНТ посередине)

//int main()
//{
//	int n;
//	cin >> n;
//	vector <int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//	cout << a[n / 2];
//	return 0;
//}

// Генерация перестановок

//void print(vector <int> a)
//{
//	for (auto now : a)
//	{
//		cout << now << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <int> a(n);
//	for (int i = 1; i <= n; i++)
//		a[i - 1] = i;
//	print(a);
//	while (next_permutation(a.begin(), a.end()))
//	{
//		print(a);
//	}
//	return 0;
//}

//void print(vector <int> a)
//{
//	for (auto now : a)
//	{
//		cout << now << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <int> a(n);
//	for (int i = 0, now; i < n; i++)
//	{
//		cin >> now;
//		a[i] = now;
//	}
//	sort(a.begin(), a.end());
//	print(a);
//	return 0;
//}

//bool cmp(pair <int, int> a, pair <int, int> b)
//{
//	if (a.second == b.second)
//		return a.first < b.first;
//	return a.second > b.second;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <pair<int, int>> v(n);
//	for (int i = 0, t_id, t_sc; i < n; i++)
//	{
//		cin >> t_id;
//		cin >> t_sc;
//		v[i] = { t_id, t_sc };
//	}
//	sort(v.begin(), v.end(), cmp);
//	for (auto now : v)
//	{
//		cout << now.first << " " << now.second;
//		cout << endl;
//	}
//	return 0;
//}

//bool cmp(pair <int, int> p1, pair <int, int> p2)
//{
//	return (p1.first * p1.first + p1.second * p1.second < p2.first* p2.first + p2.second * p2.second);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <pair <int, int>> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		a[i] = { x, y };
//	}
//	sort(a.begin(), a.end(), cmp);
//	for (auto now : a)
//		cout << now.first << " " << now.second << endl;
//	return 0;
//}