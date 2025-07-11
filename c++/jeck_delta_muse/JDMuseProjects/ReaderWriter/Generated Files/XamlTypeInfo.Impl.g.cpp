﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include <regex>
#include "XamlTypeInfo.g.h"


// XamlMetaDataProvider
namespace ReaderWriter
{
    namespace ReaderWriter_XamlTypeInfo
    {
        [Windows::Foundation::Metadata::WebHostHidden]
        public ref class XamlMetaDataProvider sealed : public ::Windows::UI::Xaml::Markup::IXamlMetadataProvider
        {
        public:
            [::Windows::Foundation::Metadata::DefaultOverload]
            virtual ::Windows::UI::Xaml::Markup::IXamlType^ GetXamlType(::Windows::UI::Xaml::Interop::TypeName type);
            virtual ::Windows::UI::Xaml::Markup::IXamlType^ GetXamlType(::Platform::String^ fullName);
            virtual ::Platform::Array<::Windows::UI::Xaml::Markup::XmlnsDefinition>^ GetXmlnsDefinitions();
            
        private:
            ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ _provider;
            property ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ Provider
            {
                ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ get();
            }
        };
    }
}

[::Windows::Foundation::Metadata::DefaultOverload]
::Windows::UI::Xaml::Markup::IXamlType^ ::ReaderWriter::ReaderWriter_XamlTypeInfo::XamlMetaDataProvider::GetXamlType(::Windows::UI::Xaml::Interop::TypeName type)
{
    return Provider->GetXamlTypeByType(type);
}

::Windows::UI::Xaml::Markup::IXamlType^ ::ReaderWriter::ReaderWriter_XamlTypeInfo::XamlMetaDataProvider::GetXamlType(Platform::String^ fullName)
{
    return Provider->GetXamlTypeByName(fullName);
}

Platform::Array<::Windows::UI::Xaml::Markup::XmlnsDefinition>^ ::ReaderWriter::ReaderWriter_XamlTypeInfo::XamlMetaDataProvider::GetXmlnsDefinitions()
{
    return ref new Platform::Array<::Windows::UI::Xaml::Markup::XmlnsDefinition>(0);
}

::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ ::ReaderWriter::ReaderWriter_XamlTypeInfo::XamlMetaDataProvider::Provider::get()
{
    if (_provider == nullptr)
    {
        _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
    }
    return _provider;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::GetXamlTypeByType(::Windows::UI::Xaml::Interop::TypeName type)
{
    auto xamlType = GetXamlTypeByName(type.Name);
    ::XamlTypeInfo::InfoProvider::XamlUserType^ userXamlType = dynamic_cast<::XamlTypeInfo::InfoProvider::XamlUserType^>(xamlType);
    if (xamlType == nullptr || (userXamlType != nullptr && userXamlType->IsReturnTypeStub && !userXamlType->IsLocalType))
    {
        ::Windows::UI::Xaml::Markup::IXamlType^ libXamlType = CheckOtherMetadataProvidersForType(type);
        if (libXamlType != nullptr)
        {
            if(libXamlType->IsConstructible || xamlType == nullptr)
            {
                xamlType = libXamlType;
            }
        }
    }
    return xamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::GetXamlTypeByName(::Platform::String^ typeName)
{
    if (typeName == nullptr || typeName->IsEmpty())
    {
        return nullptr;
    }

    auto lock = _xamlTypesCriticalSection.Lock();
    auto val = _xamlTypes.find(typeName);
    ::Windows::UI::Xaml::Markup::IXamlType^ xamlType = nullptr;
    if (val != _xamlTypes.end())
    {
        xamlType = (val->second).Resolve<::Windows::UI::Xaml::Markup::IXamlType>();
        if(xamlType != nullptr)
        {
            return xamlType;
        }
    }

    xamlType = CreateXamlType(typeName);
    ::XamlTypeInfo::InfoProvider::XamlUserType^ userXamlType = dynamic_cast<::XamlTypeInfo::InfoProvider::XamlUserType^>(xamlType);
    if (xamlType == nullptr || (userXamlType != nullptr && userXamlType->IsReturnTypeStub && !userXamlType->IsLocalType))
    {
        ::Windows::UI::Xaml::Markup::IXamlType^ libXamlType  = CheckOtherMetadataProvidersForName(typeName);
        if (libXamlType != nullptr)
        {
            if(libXamlType->IsConstructible || xamlType == nullptr)
            {
                xamlType = libXamlType;
            }
        }
    }

    if (xamlType != nullptr)
    {
        Platform::WeakReference wr(xamlType);
        _xamlTypes[xamlType->FullName] =  wr;
    }
    return xamlType;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::GetMemberByLongName(::Platform::String^ longMemberName)
{
    if (longMemberName == nullptr || longMemberName->IsEmpty())
    {
        return nullptr;
    }

    auto lock = _xamlMembersCriticalSection.Lock();
    auto val = _xamlMembers.find(longMemberName);
    if (val != _xamlMembers.end())
    {
        return val->second;
    }

    auto xamlMember = CreateXamlMember(longMemberName);
    if (xamlMember != nullptr)
    {
        _xamlMembers[longMemberName] = xamlMember;
    }
    return xamlMember;
}


::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForName(::Platform::String^ typeName)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    auto lock = _xamlTypesCriticalSection.Lock();
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(typeName);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForType(::Windows::UI::Xaml::Interop::TypeName t)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    auto lock = _xamlTypesCriticalSection.Lock();
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(t);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

// XamlSystemBaseType
::XamlTypeInfo::InfoProvider::XamlSystemBaseType::XamlSystemBaseType(::Platform::String^ name) :
    _fullName(name)
{
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::BaseType::get()
{
    throw ref new ::Platform::NotImplementedException;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::ContentProperty::get()
{
    throw ref new ::Platform::NotImplementedException;
}

::Platform::String^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::FullName::get()
{
    return _fullName;
}

::Platform::String^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::Name::get()
{
    const wchar_t* seperator = wcsrchr(_fullName->Data(), '.');
    if (seperator == nullptr)
    {
        return _fullName;
    }
    return ref new ::Platform::String(seperator);
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsArray::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsCollection::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsConstructible::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsDictionary::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsMarkupExtension::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsEnum::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsSystemType::get()
{
    throw ref new ::Platform::NotImplementedException;
}

bool ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::IsBindable::get()
{
    throw ref new ::Platform::NotImplementedException;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::ItemType::get()
{
    throw ref new ::Platform::NotImplementedException;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::KeyType::get()
{
    throw ref new ::Platform::NotImplementedException;
}

::Windows::UI::Xaml::Interop::TypeName (::XamlTypeInfo::InfoProvider::XamlSystemBaseType::UnderlyingType::get)()
{
    ::Windows::UI::Xaml::Interop::TypeName typeName;

    typeName.Name = _fullName;
    typeName.Kind = ::Windows::UI::Xaml::Interop::TypeKind::Primitive;

    return typeName;
}

::Platform::Object^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::ActivateInstance()
{
    throw ref new ::Platform::NotImplementedException;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::GetMember(::Platform::String^)
{
    throw ref new ::Platform::NotImplementedException;
}

void ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::AddToVector(::Platform::Object^, ::Platform::Object^)
{
    throw ref new ::Platform::NotImplementedException;
}

void ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::AddToMap(::Platform::Object^, ::Platform::Object^, ::Platform::Object^)
{
    throw ref new ::Platform::NotImplementedException;
}

void ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::RunInitializer()
{
    throw ref new ::Platform::NotImplementedException;
}

::Platform::Object^ ::XamlTypeInfo::InfoProvider::XamlSystemBaseType::CreateFromString(::Platform::String^)
{
    throw ref new ::Platform::NotImplementedException;
}

//XamlUserType
::XamlTypeInfo::InfoProvider::XamlUserType::XamlUserType(::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ provider, ::Platform::String^ fullName, ::Windows::UI::Xaml::Markup::IXamlType^ baseType) :
    _isArray(false),
    _isMarkupExtension(false),
    _isEnum(false),
    _isBindable(false),
    _isReturnTypeStub(false),
    _isLocalType(false),
    _fullName(fullName),
    _provider(provider),
    _baseType(baseType)
{
}

::Platform::String^ ::XamlTypeInfo::InfoProvider::XamlUserType::FullName::get()
{
    return _fullName;
}

::Platform::String^ ::XamlTypeInfo::InfoProvider::XamlUserType::Name::get()
{
    const wchar_t *seperator = wcsrchr(_fullName->Data(), '.');
    if (seperator == nullptr)
    {
        return _fullName;
    }
    return ref new ::Platform::String(seperator);
}

::Windows::UI::Xaml::Interop::TypeName (::XamlTypeInfo::InfoProvider::XamlUserType::UnderlyingType::get)()
{
    ::Windows::UI::Xaml::Interop::TypeName typeName;

    typeName.Name = _fullName;
    typeName.Kind = KindOfType;

    return typeName;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsSystemType::get()
{
    return true;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlUserType::BaseType::get()
{
    return _baseType;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsArray::get()
{
    return _isArray;
}
void ::XamlTypeInfo::InfoProvider::XamlUserType::IsArray::set(bool value)
{
    _isArray = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsCollection::get()
{
    return CollectionAdd != nullptr;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsConstructible::get()
{
    return Activator != nullptr;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsDictionary::get()
{
    return DictionaryAdd != nullptr;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsMarkupExtension::get()
{
    return _isMarkupExtension;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::IsMarkupExtension::set(bool value)
{
    _isMarkupExtension = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsEnum::get()
{
    return _isEnum;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::IsEnum::set(bool value)
{
    _isEnum = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsBindable::get()
{
    return _isBindable;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::IsBindable::set(bool value)
{
    _isBindable = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsReturnTypeStub::get()
{
    return _isReturnTypeStub;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::IsReturnTypeStub::set(bool value)
{
    _isReturnTypeStub = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlUserType::IsLocalType::get()
{
    return _isLocalType;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::IsLocalType::set(bool value)
{
    _isLocalType = value;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlUserType::ContentProperty::get()
{
    return _provider->GetMemberByLongName(_contentPropertyName);
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::ContentPropertyName::set(::Platform::String^ value)
{
    _contentPropertyName = value;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlUserType::ItemType::get()
{
    return _provider->GetXamlTypeByName(_itemTypeName);
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::ItemTypeName::set(::Platform::String^ value)
{
    _itemTypeName = value;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlUserType::KeyType::get()
{
    return _provider->GetXamlTypeByName(_keyTypeName);
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::KeyTypeName::set(::Platform::String^ value)
{
    _keyTypeName = value;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlUserType::BoxedType::get()
{
    return _boxedType;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlUserType::GetMember(::Platform::String^ name)
{
    auto val = _memberNames.find(name);
    if (val != _memberNames.end())
    {
        return _provider->GetMemberByLongName(val->second);
    }
    return nullptr;
}

::Platform::Object^ ::XamlTypeInfo::InfoProvider::XamlUserType::ActivateInstance()
{
    return Activator();
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::AddToMap(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ item)
{
    DictionaryAdd(instance, key, item);
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::AddToVector(::Platform::Object^ instance, ::Platform::Object^ item)
{
    CollectionAdd(instance, item);
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::RunInitializer()
{
    // The C++ runtime will have already run all the Static Initializers at start up.
}

::Platform::Object^ ::XamlTypeInfo::InfoProvider::XamlUserType::CreateFromString(::Platform::String^ input)
{
    // For boxed types, run the boxed type's CreateFromString method and boxing
    if (BoxedType != nullptr)
    {
        return BoxedType->CreateFromString(input);
    }

    if (CreateFromStringMethod != nullptr)
    {
        return (*CreateFromStringMethod)(input);
    }
    else
    {
        return FromStringConverter(this, input);
    }
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::SetBoxedType(::Windows::UI::Xaml::Markup::IXamlType^ boxedType)
{
    _boxedType = boxedType;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::AddMemberName(::Platform::String^ shortName)
{
    _memberNames[shortName] = FullName + "." + shortName;
}

void ::XamlTypeInfo::InfoProvider::XamlUserType::AddEnumValue(::Platform::String^ name, ::Platform::Object^ value)
{
    _enumValues[name->Data()] = value;
}

::default::uint32 (::XamlTypeInfo::InfoProvider::XamlUserType::CreateEnumUIntFromString)(::Platform::String^ input)
{
    bool found = false;

    const std::wregex regularExpression(L"^\\s+|\\s*,\\s*|\\s+$");
    uint32 val = 0;

    for (std::wcregex_token_iterator it(input->Begin(), input->End(), regularExpression, -1), end; it != end; ++it)
    {
        const std::wcsub_match& subMatch = *it;

        if (subMatch.length() == 0 )
        {
            continue;
        }

        std::wstring lookup(subMatch.first, (unsigned int)subMatch.length());

        try
        {
            auto entry = _enumValues.find(lookup);
            if (entry != _enumValues.end())
            {
                const auto f = entry->second;
                val |= safe_cast<int>(f);
            }
            else
            {
                val |= std::stoi(subMatch);
            }
            found=true;
        }
        catch (const std::invalid_argument& )
        {
            found = false;
            break;
        }
    }

    if(found)
    {
        return val;
    }
    throw ref new ::Platform::InvalidArgumentException();
}

// XamlMember
::XamlTypeInfo::InfoProvider::XamlMember::XamlMember(::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ provider, ::Platform::String^ name, ::Platform::String^ typeName) :
    _isAttachable(false),
    _isDependencyProperty(false),
    _isReadOnly(false),
    _name(name),
    _typeName(typeName),
    _provider(provider)
{
}


bool ::XamlTypeInfo::InfoProvider::XamlMember::IsAttachable::get()
{
    return _isAttachable;
}

void ::XamlTypeInfo::InfoProvider::XamlMember::IsAttachable::set(bool value)
{
    _isAttachable = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlMember::IsDependencyProperty::get()
{
    return _isDependencyProperty;
}

void ::XamlTypeInfo::InfoProvider::XamlMember::IsDependencyProperty::set(bool value)
{
    _isDependencyProperty = value;
}

bool ::XamlTypeInfo::InfoProvider::XamlMember::IsReadOnly::get()
{
    return _isReadOnly;
}

void ::XamlTypeInfo::InfoProvider::XamlMember::IsReadOnly::set(bool value)
{
    _isReadOnly = value;
}

::Platform::String^ ::XamlTypeInfo::InfoProvider::XamlMember::Name::get()
{
    return _name;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlMember::Type::get()
{
    return _provider->GetXamlTypeByName(_typeName);
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlMember::TargetType::get()
{
    return _provider->GetXamlTypeByName(_targetTypeName);
}

void ::XamlTypeInfo::InfoProvider::XamlMember::TargetTypeName::set(::Platform::String^ value)
{
    _targetTypeName = value;
}

::Platform::Object^ ::XamlTypeInfo::InfoProvider::XamlMember::GetValue(::Platform::Object^ instance)
{
    if (Getter != nullptr)
    {
        return Getter(instance);
    }
    throw ref new ::Platform::NullReferenceException();
}

void ::XamlTypeInfo::InfoProvider::XamlMember::SetValue(::Platform::Object^ instance, ::Platform::Object^ value)
{
    if (Setter != nullptr)
    {
        Setter(instance, value);
        return;
    }
    throw ref new ::Platform::NullReferenceException();
}

