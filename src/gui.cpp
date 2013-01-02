#include <stdlib.h>
#include <gtk/gtk.h>
#include "spam.h"
#include <boost/thread/thread.hpp>
//#include <boost/thread/once.hpp>
#include <boost/bind.hpp>

bool first_time = 1;

static void about_this (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Coded By Venam");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_MOUSE);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    /* If you return FALSE in the "delete-event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */

    g_print ("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */
    gtk_main_quit ();
    return FALSE;
}


static GtkWidget *xpm_label_box( gchar     *xpm_filename,
                                 gchar     *label_text )
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *image;

    /* Create box for image and label */
    box = gtk_hbox_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (box), 2);

    /* Now on to the image stuff */
    image = gtk_image_new_from_file (xpm_filename);

    /* Create a label for the button */
    label = gtk_label_new (label_text);

    /* Pack the image and label into the box */
    gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 0);
    gtk_widget_show (image);

    //gtk_widget_show (label);

    return box;
}


static void callback_entry(GtkWidget *wid, GtkWidget* thevars[4])
{
    GtkWidget *dialog = NULL;

    if(is_spamming==1)
    {   
        if(first_time==1)
        {    
            dialog = gtk_message_dialog_new (GTK_WINDOW (thevars[2]), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Starting Spamming");
            gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_MOUSE);
            gtk_dialog_run (GTK_DIALOG (dialog));
            gtk_widget_destroy (dialog);


            gdk_threads_enter();
            boost::thread z(
                    boost::bind(&do_spam, gtk_spin_button_get_value_as_int( (GtkSpinButton*) thevars[1] ) , (char*)gtk_entry_get_text( (GtkEntry*) thevars[0] )));
            gdk_threads_leave();
            first_time=0;
        }
        is_spamming=0;
        gtk_button_set_label((GtkButton *)thevars[3],"STOP");
    }
    else
    {  
        gtk_button_set_label((GtkButton *)thevars[3],"CONTINUE");
        is_spamming=1;
    }
}

gboolean  update_label(gpointer label)
{
    char str[10]; 
    std::ostringstream o;
    o << sms_sent;
    gtk_label_set_text( (GtkLabel*)label, o.str().c_str() );
    return true;
}

int main (int argc, char *argv[])
{
    GtkWidget *button      = NULL;
    GtkWidget *win         = NULL;
    GtkWidget *vbox        = NULL;
    GtkWidget *hbox        = NULL;
    GtkWidget *label       = NULL;
    GtkWidget *separ       = NULL;
    GtkWidget *image_buton = NULL;
    GtkWidget *imbox       = NULL;
    GtkWidget *wheel       = NULL;

    /* Initialize GTK+ */
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    gtk_init (&argc, &argv);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

    /* Create the main window */
    //create the main window
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //gtk_window_set_default_size((GtkWindow*)win,350,350);
    /* When the window is given the "delete-event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (win, "delete-event",
              G_CALLBACK (delete_event), NULL);
    //when receiving the destroy signal quit the app
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 10);
    gtk_window_set_title (GTK_WINDOW (win), "| - Alfa Bomb - Venam - |");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);


    ///vbox
    /* Create some boxes with buttons */
    vbox = gtk_vbox_new (FALSE,0);
    //insert it into the win
    gtk_container_add (GTK_CONTAINER (win), vbox);

    ///label
    //add a label to vbox
    /* create a new label. */
    label = gtk_label_new ("Alfa Bomb");

    /* Align the label to the left side.  We'll discuss this function and
    * others in the section on Widget Attributes. */
    gtk_misc_set_alignment (GTK_MISC (label), 0, 1);
    gtk_misc_set_padding(GTK_MISC (label),75,10);

    /* Pack the label into the vertical box (vbox box1).  Remember that
    * widgets added to a vbox will be packed one on top of the other in
    * order. */
    gtk_box_pack_start (GTK_BOX (vbox), label, FALSE, FALSE, 0);

    ///hbox
    //horizontal box here that is inside the vbox
    hbox = gtk_hbox_new (FALSE,0);
    //gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_box_pack_start(GTK_BOX (vbox), hbox,FALSE, FALSE, 0);    
    //spin
    wheel = gtk_spin_button_new_with_range(1,50,1);
    gtk_box_pack_start(GTK_BOX (hbox), wheel, FALSE, FALSE, 0);


    GtkWidget * texta;
    texta =gtk_entry_new();
    gtk_entry_set_text((GtkEntry*)texta,"8-number");
    gtk_box_pack_start (GTK_BOX (hbox),texta , TRUE, TRUE, 0); //box,child,expand,fill,padding




    ///hbox
    //horizontal box here that is inside the vbox
    hbox = gtk_hbox_new (TRUE,10);
    //gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_box_pack_end(GTK_BOX (vbox), hbox,TRUE, TRUE, 0);

    ///2 buttons at the bottom inside hbox
    button = gtk_button_new_from_stock( GTK_STOCK_CLOSE);
    g_signal_connect(button, "clicked", gtk_main_quit, NULL);
    gtk_box_pack_end (GTK_BOX (hbox), button, FALSE, FALSE, 0); //box,child,expand,fill,padding

///label
//add a label to vbox
/* create a new label. */
char str[10]; 
std::ostringstream o;
o << sms_sent;
label = gtk_label_new (  o.str().c_str() );
guint blah = g_timeout_add_seconds (1, update_label, (gpointer)label );
/* Align the label to the left side.  We'll discuss this function and
 * others in the section on Widget Attributes. */
gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
gtk_misc_set_padding(GTK_MISC (label),0,0);

//g_signal_connect (vbox, "", gtk_main_quit, NULL);

/* Pack the label into the vertical box (vbox box1).  Remember that
* widgets added to a vbox will be packed one on top of the other in
* order. */
gtk_box_pack_end (GTK_BOX (hbox), label, FALSE, FALSE, 0);


    button = gtk_button_new_with_label ("About");
    g_signal_connect (button, "clicked", G_CALLBACK(about_this), (gpointer) win);
    gtk_box_pack_end (GTK_BOX (hbox), button, FALSE, FALSE, 0); //box,child,expand,fill,padding


    ///WHEEL AND BOMB
    hbox = gtk_hbox_new(TRUE,0);
    gtk_box_pack_start(GTK_BOX (vbox), hbox,FALSE, FALSE, 0);
        
    ///image button
    image_buton = gtk_button_new();
    /* Connect the "clicked" signal of the button to our callback */
    GtkWidget* thevars[4] = {texta,wheel,win,image_buton};
    g_signal_connect (image_buton, "released",
              G_CALLBACK (callback_entry), thevars);
    /* This calls our box creating function , the box is inserted inside the button*/
    gtk_button_set_label((GtkButton*)image_buton, "BOMB!");
    //imbox = xpm_label_box ("data/emblem-danger.png","");
    //gtk_container_add (GTK_CONTAINER (image_buton), imbox);
    //gtk_container_border_width (GTK_CONTAINER(image_buton), 0);
    gtk_box_pack_start (GTK_BOX (hbox), image_buton, TRUE, TRUE, 0);


    ///Separator
    /* Creates a separator, we'll learn more about these later,
     * but they are quite simple. */
    separ = gtk_hseparator_new ();
    /* Pack the separator into the vbox. Remember each of these
     * widgets is being packed into a vbox, so they'll be stacked
     * vertically. */
    gtk_box_pack_start (GTK_BOX (vbox), separ, FALSE, FALSE, 5);



    /* Enter the main loop */
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
