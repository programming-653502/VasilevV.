object ArticleForm: TArticleForm
  Left = 387
  Top = 0
  BorderIcons = [biMinimize]
  BorderStyle = bsSingle
  Caption = 'Article'
  ClientHeight = 629
  ClientWidth = 412
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
  object BuffDBText: TDBText
    Left = 584
    Top = 309
    Width = 65
    Height = 17
    DataField = 'image'
    DataSource = DataSource2
  end
  object BackButton: TButton
    Left = 55
    Top = 596
    Width = 300
    Height = 25
    Caption = #1053#1072#1079#1072#1076
    TabOrder = 0
    OnClick = BackButtonClick
  end
  object TitleDBMemo: TDBMemo
    Left = 30
    Top = 10
    Width = 350
    Height = 63
    Alignment = taCenter
    BorderStyle = bsNone
    Color = clBtnFace
    DataField = 'title'
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object ConstMemo1: TMemo
    Left = 112
    Top = 443
    Width = 186
    Height = 43
    Alignment = taCenter
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    Lines.Strings = (
      #1048#1089#1090#1086#1088#1080#1103)
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object DescriptionDBMemo: TDBMemo
    Left = 30
    Top = 344
    Width = 350
    Height = 89
    BorderStyle = bsNone
    Color = clBtnFace
    DataField = 'description'
    DataSource = DataSource3
    TabOrder = 3
  end
  object ConstMemo2: TMemo
    Left = 112
    Top = 287
    Width = 200
    Height = 43
    Alignment = taCenter
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    Lines.Strings = (
      #1054#1087#1080#1089#1072#1085#1080#1077)
    ParentFont = False
    TabOrder = 4
  end
  object DBMemo1: TDBMemo
    Left = 30
    Top = 496
    Width = 350
    Height = 89
    BorderStyle = bsNone
    Color = clBtnFace
    DataField = 'history'
    DataSource = DataSource4
    TabOrder = 5
  end
  object WebBrowser: TWebBrowser
    Left = 30
    Top = 83
    Width = 350
    Height = 197
    TabOrder = 6
    ControlData = {
      4C0000002C2400005C1400000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object FDQuery1: TFDQuery
    Connection = MainForm.LibraryConnection
    SQL.Strings = (
      'SELECT "title" FROM "Schema1"."articles" WHERE "id" = 1')
    Left = 480
    Top = 24
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 568
    Top = 24
  end
  object FDQuery2: TFDQuery
    Connection = MainForm.LibraryConnection
    SQL.Strings = (
      'SELECT "image" FROM "Schema1"."articlesinfo" WHERE "id" = 1')
    Left = 480
    Top = 80
  end
  object DataSource2: TDataSource
    DataSet = FDQuery2
    Left = 568
    Top = 80
  end
  object FDQuery4: TFDQuery
    Connection = MainForm.LibraryConnection
    SQL.Strings = (
      'SELECT "history" FROM "Schema1"."articlesinfo" WHERE "id" = 1')
    Left = 480
    Top = 208
  end
  object DataSource3: TDataSource
    DataSet = FDQuery3
    Left = 568
    Top = 160
  end
  object DataSource4: TDataSource
    DataSet = FDQuery4
    Left = 568
    Top = 208
  end
  object FDQuery3: TFDQuery
    Connection = MainForm.LibraryConnection
    SQL.Strings = (
      
        'SELECT "description" FROM "Schema1"."articlesinfo" WHERE "id" = ' +
        '1')
    Left = 480
    Top = 152
  end
end
