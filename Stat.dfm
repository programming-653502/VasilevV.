object StatisticsForm: TStatisticsForm
  Left = 200
  Top = 200
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Statistics'
  ClientHeight = 377
  ClientWidth = 934
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object ConstLabel1: TLabel
    Left = 120
    Top = 307
    Width = 144
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1082#1085#1080#1075' '#1085#1072' '#1089#1082#1083#1072#1076#1077':'
  end
  object BooksInStockLabel: TLabel
    Left = 267
    Top = 307
    Width = 6
    Height = 13
    Caption = '0'
  end
  object ConstLabel2: TLabel
    Left = 120
    Top = 347
    Width = 94
    Height = 13
    Caption = #1054#1073#1097#1072#1103' '#1089#1090#1086#1080#1084#1086#1089#1090#1100':'
  end
  object AllPriceLabel: TLabel
    Left = 217
    Top = 347
    Width = 6
    Height = 13
    Caption = '0'
  end
  object ConstLabel3: TLabel
    Left = 416
    Top = 334
    Width = 107
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1079#1072#1082#1072#1079#1086#1074':'
  end
  object NumberOfOrdersLabel: TLabel
    Left = 526
    Top = 334
    Width = 6
    Height = 13
    Caption = '0'
  end
  object ConstLabel4: TLabel
    Left = 552
    Top = 334
    Width = 150
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1088#1086#1076#1072#1085#1085#1099#1093' '#1082#1085#1080#1075':'
  end
  object NumberOfSoldLabel: TLabel
    Left = 705
    Top = 334
    Width = 6
    Height = 13
    Caption = '0'
    Layout = tlBottom
  end
  object ConstLabel5: TLabel
    Left = 731
    Top = 334
    Width = 86
    Height = 13
    Caption = #1054#1073#1097#1072#1103' '#1087#1088#1080#1073#1099#1083#1100':'
  end
  object FullProfitLabel: TLabel
    Left = 820
    Top = 334
    Width = 6
    Height = 13
    Caption = '0'
  end
  object MainStringGrid: TStringGrid
    Left = 0
    Top = 0
    Width = 925
    Height = 289
    ColCount = 6
    DefaultColWidth = 150
    DefaultRowHeight = 25
    RowCount = 11
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object MenuButton: TButton
    Left = 10
    Top = 299
    Width = 100
    Height = 30
    Caption = #1052#1077#1085#1102
    TabOrder = 1
    OnClick = MenuButtonClick
  end
  object OrderHistoryButton: TButton
    Left = 10
    Top = 339
    Width = 100
    Height = 30
    Caption = #1048#1089#1090#1086#1088#1080#1103' '#1079#1072#1082#1072#1079#1086#1074
    TabOrder = 2
    OnClick = OrderHistoryButtonClick
  end
end
