﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <collection.h>


namespace XamlTypeInfo
{
    namespace InfoProvider
    {
        ref class XamlTypeInfoProvider sealed
        {
            struct CriticalSection
            {
                CriticalSection()
                {
                    InitializeCriticalSection(&criticalSection);
                }

                ~CriticalSection()
                {
                    DeleteCriticalSection(&criticalSection);
                }

                struct AutoLock
                {
                    AutoLock(LPCRITICAL_SECTION criticalSection)
                        : pCriticalSection(criticalSection)
                    {
                        EnterCriticalSection(criticalSection);
                    }

                    ~AutoLock()
                    {
                        LeaveCriticalSection(pCriticalSection);
                    }

                private:
                    LPCRITICAL_SECTION pCriticalSection{ nullptr };
                };

                AutoLock Lock()
                {
                    return AutoLock(&criticalSection);
                }

            private:
                CRITICAL_SECTION criticalSection;
            };

        public:
            ::Windows::UI::Xaml::Markup::IXamlType^ GetXamlTypeByName(::Platform::String^ typeName);
            ::Windows::UI::Xaml::Markup::IXamlType^ GetXamlTypeByType(::Windows::UI::Xaml::Interop::TypeName t);
            ::Windows::UI::Xaml::Markup::IXamlMember^ GetMemberByLongName(::Platform::String^ longMemberName);

        private:
            CriticalSection _xamlTypesCriticalSection;
            CriticalSection _xamlMembersCriticalSection;
            std::map<::Platform::String^, ::Platform::WeakReference> _xamlTypes;
            std::map<::Platform::String^, ::Windows::UI::Xaml::Markup::IXamlMember^> _xamlMembers;
            ::Windows::UI::Xaml::Markup::IXamlType^ CreateXamlType(::Platform::String^ typeName);
            ::Windows::UI::Xaml::Markup::IXamlMember^ CreateXamlMember(::Platform::String^ longMemberName);

            ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ _otherProviders;
            property ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ OtherProviders
            {
                ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ get();
            }

            ::Windows::UI::Xaml::Markup::IXamlType^ CheckOtherMetadataProvidersForName(::Platform::String^ typeName);
            ::Windows::UI::Xaml::Markup::IXamlType^ CheckOtherMetadataProvidersForType(::Windows::UI::Xaml::Interop::TypeName t);
        };

        ref class XamlSystemBaseType sealed : public ::Windows::UI::Xaml::Markup::IXamlType
        {
        internal:
            XamlSystemBaseType(::Platform::String^ name);

        public:
            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ BaseType 
            {
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlMember^ ContentProperty 
            {
                ::Windows::UI::Xaml::Markup::IXamlMember^ get();
            }

            virtual property ::Platform::String^ FullName
            {
                ::Platform::String^ get();
            }

            virtual property ::Platform::String^ Name
            {
                ::Platform::String^ get();
            }

            virtual property bool IsArray
            {
                bool get();
            }

            virtual property bool IsCollection
            {
                bool get();
            }

            virtual property bool IsConstructible
            {
                bool get();
            }

            virtual property bool IsDictionary
            {
                bool get();
            }

            virtual property bool IsMarkupExtension
            {
                bool get();
            }

            virtual property bool IsEnum
            {
                bool get();
            }

            virtual property bool IsSystemType
            {
                bool get();
            }

            virtual property bool IsBindable
            {
                bool get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ ItemType
            {
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ KeyType
            {
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property ::Windows::UI::Xaml::Interop::TypeName UnderlyingType
            {
                ::Windows::UI::Xaml::Interop::TypeName get();
            }

            virtual ::Platform::Object^ ActivateInstance();
            virtual ::Windows::UI::Xaml::Markup::IXamlMember^ GetMember(::Platform::String^ name);
            virtual void AddToVector(::Platform::Object^ instance, ::Platform::Object^ value);
            virtual void AddToMap(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ value);
            virtual void RunInitializer();
            virtual ::Platform::Object^ CreateFromString(::Platform::String^ value);

        private:
            ::Platform::String^ _fullName;
        };

        ref class XamlUserType sealed : public [::Platform::Metadata::RuntimeClassName] ::Windows::UI::Xaml::Markup::IXamlType2
        {
        internal:
            XamlUserType(::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ provider, ::Platform::String^ fullName, ::Windows::UI::Xaml::Markup::IXamlType^ baseType);            

        public:
            // --- Interface methods ----
            virtual property ::Platform::String^ FullName
            {
                ::Platform::String^ get();
            }

            virtual property ::Platform::String^ Name
            {
                ::Platform::String^ get();
            }

            virtual property ::Windows::UI::Xaml::Interop::TypeName UnderlyingType
            {
                ::Windows::UI::Xaml::Interop::TypeName get();
            }

            virtual property bool IsSystemType
            {
                bool get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ BaseType 
            { 
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property bool IsArray 
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property bool IsCollection 
            { 
                bool get();
            }

            virtual property bool IsConstructible 
            { 
                bool get();
            }

            virtual property bool IsDictionary 
            { 
                bool get();
            }

            virtual property bool IsMarkupExtension 
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property bool IsEnum 
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property bool IsBindable
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlMember^ ContentProperty 
            { 
                ::Windows::UI::Xaml::Markup::IXamlMember^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ ItemType 
            { 
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ KeyType 
            { 
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ BoxedType
            { 
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual ::Windows::UI::Xaml::Markup::IXamlMember^ GetMember(::Platform::String^ name);
            virtual ::Platform::Object^ ActivateInstance();
            virtual void AddToMap(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ value);
            virtual void AddToVector(::Platform::Object^ instance, ::Platform::Object^ value);
            virtual void RunInitializer();
            virtual ::Platform::Object^ CreateFromString(::Platform::String^ value);
            // --- End of Interface methods

            property bool IsReturnTypeStub
            { 
                bool get();
                internal: void set(bool value);
            }

            property bool IsLocalType
            {
                bool get();
                internal:  void set(bool value);
            }

        internal:
            typedef ::Platform::Object^ (*ActivatorFn)();
            typedef void (*AddToCollectionFn)(::Platform::Object^ instance, ::Platform::Object^ item);
            typedef void (*AddToDictionaryFn)(::Platform::Object^ instance, ::Platform::Object^ key, ::Platform::Object^ item);
            typedef ::Platform::Object^ (*CreateFromStringFn)(::Platform::String^);
            typedef ::Platform::Object^ (*StringConverterFn)(::XamlTypeInfo::InfoProvider::XamlUserType^ userType, ::Platform::String^ input);

            property ActivatorFn Activator;
            property AddToCollectionFn CollectionAdd;
            property AddToDictionaryFn DictionaryAdd;
            property CreateFromStringFn CreateFromStringMethod;
            property ::Windows::UI::Xaml::Interop::TypeKind KindOfType;
            property StringConverterFn FromStringConverter;

            property ::Platform::String^ ContentPropertyName
            {
                void set(::Platform::String^ value);
            }

            property ::Platform::String^ ItemTypeName
            {
                void set(::Platform::String^ value);
            }

            property ::Platform::String^ KeyTypeName
            {
                void set(::Platform::String^ value);
            }

            void SetBoxedType(::Windows::UI::Xaml::Markup::IXamlType^ boxedType);
            void AddMemberName(::Platform::String^ shortName);
            void AddEnumValue(::Platform::String^ name, ::Platform::Object^ value);
            uint32 CreateEnumUIntFromString(::Platform::String^ input);

        private:
            ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ _provider;
            ::Windows::UI::Xaml::Markup::IXamlType^ _baseType;
            ::Platform::String^ _contentPropertyName;
            ::Platform::String^ _itemTypeName;
            ::Platform::String^ _keyTypeName;
            ::Platform::String^ _fullName;
            std::map<::Platform::String^, ::Platform::String^> _memberNames;
            std::map<std::wstring, ::Platform::Object^> _enumValues;
            bool _isArray = false;
            bool _isMarkupExtension = false;
            bool _isEnum = false;
            bool _isBindable = false;
            bool _isReturnTypeStub = false;
            bool _isLocalType = false;
            ::Windows::UI::Xaml::Markup::IXamlType^ _boxedType;
        };

        ref class XamlMember sealed : public ::Windows::UI::Xaml::Markup::IXamlMember
        {
        internal:
            XamlMember(::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ provider, ::Platform::String^ name, ::Platform::String^ typeName);

            typedef ::Platform::Object^ (*PropertyGetterFn)(::Platform::Object^ instance);
            typedef void (*PropertySetterFn)(::Platform::Object^ instance, ::Platform::Object^ value);

            property PropertyGetterFn Getter;
            property PropertySetterFn Setter;

        public:
            virtual property bool IsAttachable
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property bool IsDependencyProperty 
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property bool IsReadOnly
            { 
                bool get();
                internal: void set(bool value);
            }

            virtual property ::Platform::String^ Name
            { 
                ::Platform::String^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ Type
            {
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual property ::Windows::UI::Xaml::Markup::IXamlType^ TargetType
            {
                ::Windows::UI::Xaml::Markup::IXamlType^ get();
            }

            virtual ::Platform::Object^ GetValue(::Platform::Object^ instance);
            virtual void SetValue(::Platform::Object^ instance, ::Platform::Object^ value);

        internal:
            virtual property ::Platform::String^ TargetTypeName
            {
                void set(::Platform::String^ value);
            }

        private:
            bool _isAttachable;
            bool _isDependencyProperty;
            bool _isReadOnly; 
            ::Platform::String^ _name;
            ::Platform::String^ _targetTypeName;
            ::Platform::String^ _typeName;
            ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ _provider;
        };
    }
}

