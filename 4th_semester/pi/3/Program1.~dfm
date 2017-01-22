object MainForm: TMainForm
  Left = 192
  Top = 124
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 204
  ClientWidth = 429
  Color = clBtnFace
  Constraints.MinHeight = 235
  Constraints.MinWidth = 445
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object WidthLabel: TLabel
    Left = 0
    Top = 0
    Width = 39
    Height = 13
    Caption = #1064#1080#1088#1080#1085#1072
  end
  object HeightLabel: TLabel
    Left = 136
    Top = 0
    Width = 38
    Height = 13
    Caption = #1042#1099#1089#1086#1090#1072
  end
  object DataGrid: TStringGrid
    Left = 0
    Top = 48
    Width = 425
    Height = 153
    ColCount = 6
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object WidthUpDown: TUpDown
    Left = 105
    Top = 18
    Width = 16
    Height = 21
    Associate = WidthEdit
    Min = 1
    Position = 1
    TabOrder = 1
    Wrap = False
  end
  object WidthEdit: TEdit
    Left = 0
    Top = 18
    Width = 105
    Height = 21
    ReadOnly = True
    TabOrder = 2
    Text = '1'
    OnChange = WidthChange
  end
  object HeightEdit: TEdit
    Left = 136
    Top = 18
    Width = 105
    Height = 21
    ReadOnly = True
    TabOrder = 3
    Text = '1'
    OnChange = HeightChange
  end
  object HeightUpDown: TUpDown
    Left = 241
    Top = 18
    Width = 16
    Height = 21
    Associate = HeightEdit
    Min = 1
    Position = 1
    TabOrder = 4
    Wrap = False
  end
  object Process: TButton
    Left = 272
    Top = 16
    Width = 155
    Height = 25
    Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100
    TabOrder = 5
    OnClick = ProcessClick
  end
  object MainMenu1: TMainMenu
    Left = 272
    Top = 65528
    object FileMenu: TMenuItem
      Caption = #1060#1072#1081#1083
      object ImportMenu: TMenuItem
        Caption = #1048#1084#1087#1086#1088#1090
        OnClick = ImportMenuClick
      end
      object ExportMenu: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090
        OnClick = ExportMenuClick
      end
      object ExitMenu: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = ExitMenuClick
      end
    end
    object N1: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = N2Click
    end
  end
  object ImportDialog: TOpenDialog
    Left = 304
    Top = 65528
  end
  object ExportDialog: TSaveDialog
    Left = 336
    Top = 65528
  end
end
