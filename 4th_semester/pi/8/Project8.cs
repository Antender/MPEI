//$/r:District.dll
//$/r:LayoutMgr.dll
//$/r:SourceGrid.dll
//$/t:winexe
//& RunInOwnWindow

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

using LayoutManager;

using SourceGrid;

public class MainForm : Form
{
    Grid grid;
    Button create;
    Button process;
    int height;
    Label heightLabel;
    Label thresholdLabel;
    private LayoutControl buttons;
    private LayoutControl heightControl;
    private LayoutControl thresholdControl;
    private LayoutControl window;
    TextBox heightBox;
    TextBox thresholdBox;

    public MainForm()
    {
        heightControl = new LayoutControl(new QLayout(QLayout.Direction.Vertical));
        thresholdControl = new LayoutControl(new QLayout(QLayout.Direction.Vertical));
        buttons = new LayoutControl(new QLayout(QLayout.Direction.Horizontal));
        window  = new LayoutControl(new RubberLayout());
        window.Dock = DockStyle.Fill;

        heightBox = new TextBox();
        thresholdBox = new TextBox();
        heightLabel = new Label();
        thresholdLabel = new Label();

        create = new Button();
        process = new Button();
        grid = new Grid();

        heightLabel.Text = "Высота";
        thresholdLabel.Text = "Порог";
        create.Text = "Создать массив";
        process.Text = "Обработать";

        create.Click += buttonCreate;
        process.Click += buttonProcess;

        heightControl.Controls.AddRange(new Control[]{heightLabel,heightBox});
        thresholdControl.Controls.AddRange(new Control[]{thresholdLabel,thresholdBox});
        buttons.Controls.AddRange(new Control[]{heightControl,thresholdControl,create,process});
        buttons.Bounds = new Rectangle(0,0,400,40);
        grid.Bounds = new Rectangle(0,40,400,160);
        window.Size = new Size (400,200);
        window.Controls.AddRange(new Control[]{buttons,grid});
        Controls.Add(window);
    }

    private static void Main(string [] args)
    {
        Application.EnableVisualStyles();
        Application.SetCompatibleTextRenderingDefault(false);
        Application.ThreadException +=
        new System.Threading.ThreadExceptionEventHandler(ThreadException);
        try
        {
            Application.Run(new MainForm());
        }
        catch (Exception ex)
        {
            MessageBox.Show(ex.Message, "Error",
            MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }

    private static void ThreadException(
        object sender, System.Threading.ThreadExceptionEventArgs e)
    {
        MessageBox.Show(e.Exception.Message, "Error",
        MessageBoxButtons.OK, MessageBoxIcon.Error);
        Application.Exit();
    }

    void buttonCreate(Object sender, EventArgs e)
    {
        var converted = false;
        try
        {
            height = int.Parse(heightBox.Text);
            converted = true;
        } catch {}
        if (converted)
        {
            grid.Size = new Size(400,160);
            grid.FixedRows = 1;
            grid.ColumnsCount = 3;
            grid.Rows.Insert(0);
            grid[0,0] = new SourceGrid.Cells.ColumnHeader("Округ");
            grid[0,1] = new SourceGrid.Cells.ColumnHeader("Губернатор");
            grid[0,2] = new SourceGrid.Cells.ColumnHeader("Площадь");
            for (int i=1; i<=height; i++)
            {
                grid.Rows.Insert(i);
                grid[i,0] = new SourceGrid.Cells.Cell("",typeof(string));
                grid[i,1] = new SourceGrid.Cells.Cell("",typeof(string));
                grid[i,2] = new SourceGrid.Cells.Cell(0.0,typeof(float));
            }
            grid.AutoSizeCells();
        }
    }

    void buttonProcess(Object sender, EventArgs e)
    {
        DistrictList templist = new DistrictList();
        for (int i=1;i<=height;i++)
        {
            templist.Add(new District((string)grid[i,0].Value,(string)grid[i,1].Value,(float)grid[i,2].Value));
        }
        float threshold = float.Parse(thresholdBox.Text);
        MessageBox.Show("Результат: "+ templist.SumThreshold(threshold).ToString(),"Сумма выше порогового значения");
        grid.Refresh();
    }
}