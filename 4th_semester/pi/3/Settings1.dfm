object Settings: TSettings
  Left = 192
  Top = 124
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 136
  ClientWidth = 280
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 120
    Top = 96
    Width = 49
    Height = 13
    Caption = #1048#1085#1090#1077#1088#1074#1072#1083
  end
  object Mode: TRadioGroup
    Left = 8
    Top = 8
    Width = 265
    Height = 81
    Caption = #1056#1077#1078#1080#1084
    ItemIndex = 1
    Items.Strings = (
      #1053#1086#1084#1077#1088' '#1089#1090#1088#1086#1082#1080' '#1084#1080#1085#1080#1084'. '#1082#1086#1083'-'#1074#1086#1084' '#1074' '#1080#1085#1090#1077#1088#1074#1072#1083#1077
      #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1099#1077' '#1101#1083#1077#1084#1077#1085#1090#1099' '#1089#1090#1088#1086#1082)
    TabOrder = 0
  end
  object Minimum: TEdit
    Left = 8
    Top = 112
    Width = 129
    Height = 21
    TabOrder = 1
  end
  object Maximum: TEdit
    Left = 144
    Top = 112
    Width = 129
    Height = 21
    TabOrder = 2
  end
end
