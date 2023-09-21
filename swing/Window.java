import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.SwingConstants;


/**
 * Main window class that contains a multi-line text area and three buttons.
 */
public class Window extends JFrame 
{
    private static final long serialVersionUID = 1L;

    private Client client;
    private JTextArea textArea;
    private JButton button1;
    private JButton button2;
    private JButton button3;

    // public static void main(String[] args)
    // {
    // new Window(client);
    // }

    public Window(Client client) {

        // Client - Server communication
        this.client = client;


        //setText getText for using send from client and communicating with Window

        // Set up text area with scrollbars for requests
        textArea = new JTextArea(20, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);


        // Set up buttons
        button1 = new JButton("New Request");
        button2 = new JButton("Send Request");
        button3 = new JButton("Exit");

        // Add menu bar
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);
        
        //  Add menu
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        // Add Abstract Action for adding line
        AbstractAction newLineAction = new AbstractAction("New Request")
        {
        @Override
        public void actionPerformed(ActionEvent e) {
            textArea.setText(null);
        }
        };

        // Add Abstract Action for adding line
        AbstractAction Print = new AbstractAction("Send Request")
        {
        @Override
        public void actionPerformed(ActionEvent e) {
            String request = textArea.getText();
            String reponse = client.send(request);
            textArea.setText(null);
            textArea.append(reponse);
        }
        };

        // Add Abstract Action to exit the application
        AbstractAction exitAction = new AbstractAction("Exit") {
        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
        };

        menu.add(newLineAction);
        menu.add(Print);
        menu.add(exitAction);

        // Add toolbar
        JToolBar toolbar = new JToolBar();
        add(toolbar, BorderLayout.NORTH);

        toolbar.add(newLineAction);
        toolbar.add(Print);
        toolbar.add(exitAction);

        // Add action listeners to buttons
        button1.addActionListener(new Button1Listener());
        button2.addActionListener(new Button2Listener());
        button3.addActionListener(new Button3Listener());

        // Add buttons to button panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);

        

        // Add text area and button panel to main window
        add(scrollPane, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);

        // Set up main window
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }


// Version 3

// Button 1 Listener
class Button1Listener implements ActionListener
{
    public void actionPerformed(ActionEvent e) {
        textArea.setText(null);
    }
}

// Button 2 Listener
class Button2Listener implements ActionListener
{
    public void actionPerformed(ActionEvent e) {
        String request = textArea.getText();
        String reponse = client.send(request);
        textArea.setText(null);
        textArea.append(reponse);
    }
}

// Button 3 Listener
class Button3Listener implements ActionListener
{
    public void actionPerformed(ActionEvent e) {
        System.exit(0);
    }
}

}

