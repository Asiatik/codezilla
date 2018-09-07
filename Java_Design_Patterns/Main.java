package com.company;


import java.util.ArrayList;

//Booking class which tells us about the number and type of booking
// Here 0 represents single booking where only the reception is to be informed
// 1 represents corporate booking where the reception and the manager are to be informed
// 2 represents bulk booking where the reception , manager and the food agency is to be informed
/*
    food agency - only through email
    manager - sms and email
    reception - sms
 */
class Booking
{
    private String name;
    private int type ;
    public Booking (String nameee , int typeee)
    {
        name=nameee;
        type=typeee;
    }
    public int getbookingtype()
    {
        return type;
    }
    public String getName()
    {
        return  name;
    }

}

 interface PersonalNotification
{

     public void send();
}

class NotificationForFoodAgency implements  PersonalNotification
{
    Booking book;
    public NotificationForFoodAgency(Booking booking)
    {
        book = booking;
    }
    public void send()
    {
        System.out.println("Food Agency informed through email  for the arrival of" + book.getName());
    }
}

class NotificationForManager implements  PersonalNotification
{
    Booking book;
    public NotificationForManager(Booking booking)
    {
        book = booking;
    }
    public void send()
    {
        System.out.println("Manager informed through email   and sms for the arrival " + book.getName());
    }
}

class NotificationForReception implements  PersonalNotification
{
    Booking book;
    public NotificationForReception(Booking booking)
    {
        book=booking;
    }
    public void send()
    {
        System.out.println("Reception informed through sms for the arrival of "+ book.getName());
    }
}



class Notification
{
    private ArrayList<PersonalNotification>  listOfNotification ;
    public  Notification()
    {
        listOfNotification =new ArrayList<PersonalNotification>();
    }
    public void sendAll()
    {
        for ( PersonalNotification personalNotification : listOfNotification )
            personalNotification.send();
    }
    public void add(PersonalNotification  personalNotification)
    {
        listOfNotification.add(personalNotification);
    }


}


class NotificationBuilder
{
    Booking book ;
    Notification notification;

    public NotificationBuilder(Booking b)
    {
        book=b;
    }
    public void ConstructNotification()
    {
        notification=new Notification();
        if(book.getbookingtype() == 0)
            notification.add(new NotificationForReception(book));
        else if (book.getbookingtype()==1)
        {
            notification.add(new NotificationForReception(book));
            notification.add(new NotificationForManager(book));
        }
        else if(book.getbookingtype()==2)
        {
            notification.add(new NotificationForReception(book));
            notification.add(new NotificationForManager(book));
            notification.add(new NotificationForFoodAgency(book));
        }
    }
    public void sendNotifications()
    {
        notification.sendAll();
    }

}



// This is the Client Code that allows us to test the actual builder.
public class Main {

    public static void main(String[] args) {
	// write your code here
        Booking newbook=new Booking("Suryasis",2);
        NotificationBuilder notificationBuilder=new NotificationBuilder(newbook);
        notificationBuilder.ConstructNotification();
        notificationBuilder.sendNotifications();



    }
}
