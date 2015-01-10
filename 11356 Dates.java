import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

class Main
{
    public static void main (String args[]) {
        Scanner scanner = new Scanner(System.in);
        
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            String line = scanner.next();
            String[] parts = line.split("-");
            int year = Integer.parseInt(parts[0]);
            String month = parts[1];
            int date = Integer.parseInt(parts[2]);
            
            Calendar cal = new GregorianCalendar(year, getMonthZeroBased(month), date);
            
            int increase = scanner.nextInt();
            cal.add(Calendar.DAY_OF_MONTH, increase);
            System.out.printf("Case %d: %d-%s-%02d\n", t, cal.get(Calendar.YEAR), monthIntToName(cal.get(Calendar.MONTH)), cal.get(Calendar.DAY_OF_MONTH));
        }
    }
    
    private static int getMonthZeroBased(String month) {
        if (month.equals("January"))
            return 0;
        else if (month.equals("February"))
            return 1;
        else if (month.equals("March"))
            return 2;
        else if (month.equals("April"))
            return 3;
        else if (month.equals("May"))
            return 4;
        else if (month.equals("June"))
            return 5;
        else if (month.equals("July"))
            return 6;
        else if (month.equals("August"))
            return 7;
        else if (month.equals("September"))
            return 8;
        else if (month.equals("October"))
            return 9;
        else if (month.equals("November"))
            return 10;
        else
            return 11;
    }
    
    private static String monthIntToName(int month) {
        switch(month)
        {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        default:
            return "December";
        }
    }
}