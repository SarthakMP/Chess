using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Smooth_Sliding_objects
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {   


        public MainWindow()
        {
            InitializeComponent();
        }

        public class m_object {
            Grid grid;
            Rectangle rec;
            TextBlock block;

            public m_object(int index) {
                grid = new();
                rec = new() {
                    Fill = new SolidColorBrush(Colors.Beige),
                    RadiusX = 10,
                    RadiusY = 10,
                    Margin = new(5)
                };


                block = new() { 
                    Text = index.ToString(),
                };
                grid.Children.Add(rec);
                grid.Children.Add(block);
                
                grid.VerticalAlignment = VerticalAlignment.Stretch;
                grid.HorizontalAlignment = HorizontalAlignment.Stretch;
            }
        }

        int count = 0;
        private void Window_KeyDown(object sender, KeyEventArgs e)
        {

            if (e.Key == Key.A && Keyboard.Modifiers == ModifierKeys.Shift) {
                m_object m_Object = new(count);
                _Viewer.Items.Add(m_Object);

            }
            count++;
        }
    }
}