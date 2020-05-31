#include "Matrix.h"

void main()
{
    try
    {
        cout << "Enter dimensions of first matrix:\n\nRows: ";
        unsigned m = 0;
        cin >> m;
        cout << "Columns: ";
        unsigned n = 0;
        cin >> n;

        cout << "Enter dimensions of second matrix:\n\nRows: ";
        unsigned k = 0;
        cin >> k;
        cout << "Columns: ";
        unsigned l = 0;
        cin >> l;

        Matrix a(m,n), b(k,l);

        cout << "\nEnter data of first matrix: " << m * n << " int's: \n";
        cin >> a;

        cout << "\nEnter data of second matrix: " << k * l << " int's: \n";
        cin >> b;

        Matrix d = a + b;
        cout << "a + b = " << d << endl;
    }
    catch(Exception& ex)
    {
        cout << "Error: " << ex.Excp_massage() << endl;
    }
    catch(...)
    {
        cout << "Error: something goes wrong!" << endl;
    }

    system("pause");
}