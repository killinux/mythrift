package Test;

import java.util.Calendar;
import Test.UserProfile;
import Test.UserStorage;

    public class UserStorageHandler implements Test.UserStorage.Iface {
        @Override
        public void repeat(UserProfile user) {
            System.out.println("Repeat:\n");
            System.out.println("User's ID: " + user.uid + "\nUser's Name: " + user.name + "\nUser's Blurb: " + user.blurb+ "\n");
        }

    public void daysold(UserProfile user){
        System.out.println("Days Old:\n");
        int month = Calendar.getInstance().get(Calendar.MONTH);
        int year = Calendar.getInstance().get(Calendar.YEAR);
        int agem;
        int agey;
            if (month>user.month){
                agem=(month-user.month)*30;
                agey=(year-user.year)*360;
                }
            else{
                agem=month*30;
                agey=(year-user.year-1)*360;
            }
        int age=agem+agey+user.day;
        System.out.println("User is approximately " + age +" days old.\n");
        }
}
