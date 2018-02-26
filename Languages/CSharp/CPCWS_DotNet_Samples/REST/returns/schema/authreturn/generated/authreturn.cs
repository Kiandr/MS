﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.5483
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System.Xml.Serialization;

// 
// This source code was auto-generated by xsd, Version=2.0.50727.1432.
// 


/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
[System.Xml.Serialization.XmlRootAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2", IsNullable=false)]
public partial class links {
    
    private LinkType[] linkField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("link")]
    public LinkType[] link {
        get {
            return this.linkField;
        }
        set {
            this.linkField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
[System.Xml.Serialization.XmlRootAttribute("link", Namespace="http://www.canadapost.ca/ws/authreturn-v2", IsNullable=false)]
public partial class LinkType {
    
    private string hrefField;
    
    private string relField;
    
    private string indexField;
    
    private string mediatypeField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute(DataType="anyURI")]
    public string href {
        get {
            return this.hrefField;
        }
        set {
            this.hrefField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string rel {
        get {
            return this.relField;
        }
        set {
            this.relField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute(DataType="nonNegativeInteger")]
    public string index {
        get {
            return this.indexField;
        }
        set {
            this.indexField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute("media-type", DataType="normalizedString")]
    public string mediatype {
        get {
            return this.mediatypeField;
        }
        set {
            this.mediatypeField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class NotificationsType {
    
    private NotificationsTypeNotification[] notificationField;
    
    private NotificationsTypeEmailsubject emailsubjectField;
    
    private bool emailsubjectFieldSpecified;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("notification")]
    public NotificationsTypeNotification[] notification {
        get {
            return this.notificationField;
        }
        set {
            this.notificationField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("email-subject")]
    public NotificationsTypeEmailsubject emailsubject {
        get {
            return this.emailsubjectField;
        }
        set {
            this.emailsubjectField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlIgnoreAttribute()]
    public bool emailsubjectSpecified {
        get {
            return this.emailsubjectFieldSpecified;
        }
        set {
            this.emailsubjectFieldSpecified = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class NotificationsTypeNotification {
    
    private string emailField;
    
    private bool onshipmentField;
    
    private bool onexceptionField;
    
    private bool ondeliveryField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string email {
        get {
            return this.emailField;
        }
        set {
            this.emailField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("on-shipment")]
    public bool onshipment {
        get {
            return this.onshipmentField;
        }
        set {
            this.onshipmentField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("on-exception")]
    public bool onexception {
        get {
            return this.onexceptionField;
        }
        set {
            this.onexceptionField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("on-delivery")]
    public bool ondelivery {
        get {
            return this.ondeliveryField;
        }
        set {
            this.ondeliveryField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public enum NotificationsTypeEmailsubject {
    
    /// <remarks/>
    tracking,
    
    /// <remarks/>
    [System.Xml.Serialization.XmlEnumAttribute("customer-ref-1")]
    customerref1,
    
    /// <remarks/>
    [System.Xml.Serialization.XmlEnumAttribute("customer-ref-2")]
    customerref2,
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class ReferencesType {
    
    private string customerref1Field;
    
    private string customerref2Field;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("customer-ref-1", DataType="normalizedString")]
    public string customerref1 {
        get {
            return this.customerref1Field;
        }
        set {
            this.customerref1Field = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("customer-ref-2", DataType="normalizedString")]
    public string customerref2 {
        get {
            return this.customerref2Field;
        }
        set {
            this.customerref2Field = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class AuthSettlementInfoType {
    
    private string paidbycustomerField;
    
    private string contractidField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("paid-by-customer")]
    public string paidbycustomer {
        get {
            return this.paidbycustomerField;
        }
        set {
            this.paidbycustomerField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("contract-id")]
    public string contractid {
        get {
            return this.contractidField;
        }
        set {
            this.contractidField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class PrintPreferencesType {
    
    private PrintPreferencesTypeOutputformat outputformatField;
    
    private bool outputformatFieldSpecified;
    
    private PrintPreferencesTypeEncoding encodingField;
    
    private bool encodingFieldSpecified;
    
    private bool showpackinginstructionsField;
    
    public PrintPreferencesType() {
        this.showpackinginstructionsField = true;
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("output-format")]
    public PrintPreferencesTypeOutputformat outputformat {
        get {
            return this.outputformatField;
        }
        set {
            this.outputformatField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlIgnoreAttribute()]
    public bool outputformatSpecified {
        get {
            return this.outputformatFieldSpecified;
        }
        set {
            this.outputformatFieldSpecified = value;
        }
    }
    
    /// <remarks/>
    public PrintPreferencesTypeEncoding encoding {
        get {
            return this.encodingField;
        }
        set {
            this.encodingField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlIgnoreAttribute()]
    public bool encodingSpecified {
        get {
            return this.encodingFieldSpecified;
        }
        set {
            this.encodingFieldSpecified = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("show-packing-instructions")]
    [System.ComponentModel.DefaultValueAttribute(true)]
    public bool showpackinginstructions {
        get {
            return this.showpackinginstructionsField;
        }
        set {
            this.showpackinginstructionsField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public enum PrintPreferencesTypeOutputformat {
    
    /// <remarks/>
    [System.Xml.Serialization.XmlEnumAttribute("8.5x11")]
    Item85x11,
    
    /// <remarks/>
    [System.Xml.Serialization.XmlEnumAttribute("4x6")]
    Item4x6,
    
    /// <remarks/>
    [System.Xml.Serialization.XmlEnumAttribute("3x5")]
    Item3x5,
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public enum PrintPreferencesTypeEncoding {
    
    /// <remarks/>
    PDF,
    
    /// <remarks/>
    ZPL,
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class ParcelCharacteristicsType {
    
    private decimal weightField;
    
    private bool weightFieldSpecified;
    
    private ParcelCharacteristicsTypeDimensions dimensionsField;
    
    /// <remarks/>
    public decimal weight {
        get {
            return this.weightField;
        }
        set {
            this.weightField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlIgnoreAttribute()]
    public bool weightSpecified {
        get {
            return this.weightFieldSpecified;
        }
        set {
            this.weightFieldSpecified = value;
        }
    }
    
    /// <remarks/>
    public ParcelCharacteristicsTypeDimensions dimensions {
        get {
            return this.dimensionsField;
        }
        set {
            this.dimensionsField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class ParcelCharacteristicsTypeDimensions {
    
    private decimal lengthField;
    
    private decimal widthField;
    
    private decimal heightField;
    
    /// <remarks/>
    public decimal length {
        get {
            return this.lengthField;
        }
        set {
            this.lengthField = value;
        }
    }
    
    /// <remarks/>
    public decimal width {
        get {
            return this.widthField;
        }
        set {
            this.widthField = value;
        }
    }
    
    /// <remarks/>
    public decimal height {
        get {
            return this.heightField;
        }
        set {
            this.heightField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class ReceiverType {
    
    private string nameField;
    
    private string companyField;
    
    private string emailField;
    
    private string receivervoicenumberField;
    
    private DomesticAddressDetailsType domesticaddressField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string name {
        get {
            return this.nameField;
        }
        set {
            this.nameField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string company {
        get {
            return this.companyField;
        }
        set {
            this.companyField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string email {
        get {
            return this.emailField;
        }
        set {
            this.emailField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("receiver-voice-number", DataType="normalizedString")]
    public string receivervoicenumber {
        get {
            return this.receivervoicenumberField;
        }
        set {
            this.receivervoicenumberField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("domestic-address")]
    public DomesticAddressDetailsType domesticaddress {
        get {
            return this.domesticaddressField;
        }
        set {
            this.domesticaddressField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class DomesticAddressDetailsType {
    
    private string addressline1Field;
    
    private string addressline2Field;
    
    private string cityField;
    
    private string provinceField;
    
    private string postalcodeField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("address-line-1", DataType="normalizedString")]
    public string addressline1 {
        get {
            return this.addressline1Field;
        }
        set {
            this.addressline1Field = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("address-line-2", DataType="normalizedString")]
    public string addressline2 {
        get {
            return this.addressline2Field;
        }
        set {
            this.addressline2Field = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string city {
        get {
            return this.cityField;
        }
        set {
            this.cityField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string province {
        get {
            return this.provinceField;
        }
        set {
            this.provinceField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("postal-code")]
    public string postalcode {
        get {
            return this.postalcodeField;
        }
        set {
            this.postalcodeField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
public partial class ReturnerType {
    
    private string nameField;
    
    private string companyField;
    
    private DomesticAddressDetailsType domesticaddressField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string name {
        get {
            return this.nameField;
        }
        set {
            this.nameField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(DataType="normalizedString")]
    public string company {
        get {
            return this.companyField;
        }
        set {
            this.companyField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("domestic-address")]
    public DomesticAddressDetailsType domesticaddress {
        get {
            return this.domesticaddressField;
        }
        set {
            this.domesticaddressField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
[System.Xml.Serialization.XmlRootAttribute("authorized-return", Namespace="http://www.canadapost.ca/ws/authreturn-v2", IsNullable=false)]
public partial class AuthorizedReturnType {
    
    private string servicecodeField;
    
    private ReturnerType returnerField;
    
    private ReceiverType receiverField;
    
    private ParcelCharacteristicsType parcelcharacteristicsField;
    
    private PrintPreferencesType printpreferencesField;
    
    private AuthSettlementInfoType settlementinfoField;
    
    private ReferencesType referencesField;
    
    private NotificationsType notificationsField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("service-code", DataType="normalizedString")]
    public string servicecode {
        get {
            return this.servicecodeField;
        }
        set {
            this.servicecodeField = value;
        }
    }
    
    /// <remarks/>
    public ReturnerType returner {
        get {
            return this.returnerField;
        }
        set {
            this.returnerField = value;
        }
    }
    
    /// <remarks/>
    public ReceiverType receiver {
        get {
            return this.receiverField;
        }
        set {
            this.receiverField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("parcel-characteristics")]
    public ParcelCharacteristicsType parcelcharacteristics {
        get {
            return this.parcelcharacteristicsField;
        }
        set {
            this.parcelcharacteristicsField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("print-preferences")]
    public PrintPreferencesType printpreferences {
        get {
            return this.printpreferencesField;
        }
        set {
            this.printpreferencesField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("settlement-info")]
    public AuthSettlementInfoType settlementinfo {
        get {
            return this.settlementinfoField;
        }
        set {
            this.settlementinfoField = value;
        }
    }
    
    /// <remarks/>
    public ReferencesType references {
        get {
            return this.referencesField;
        }
        set {
            this.referencesField = value;
        }
    }
    
    /// <remarks/>
    public NotificationsType notifications {
        get {
            return this.notificationsField;
        }
        set {
            this.notificationsField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(Namespace="http://www.canadapost.ca/ws/authreturn-v2")]
[System.Xml.Serialization.XmlRootAttribute("authorized-return-info", Namespace="http://www.canadapost.ca/ws/authreturn-v2", IsNullable=false)]
public partial class AuthorizedReturnInfoType {
    
    private string trackingpinField;
    
    private LinkType[] linksField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("tracking-pin", DataType="normalizedString")]
    public string trackingpin {
        get {
            return this.trackingpinField;
        }
        set {
            this.trackingpinField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlArrayItemAttribute("link", IsNullable=false)]
    public LinkType[] links {
        get {
            return this.linksField;
        }
        set {
            this.linksField = value;
        }
    }
}